#include <iostream>
#include <QtCore/QThread>
#include <zconf.h>
#include "backend.h"

#include <DDSNodeInterface.h>
#include <GamePad.h>
#include <GamePadSupport.h>
#include <iostream>

class TwistListener : public Generic_Listener {
public:
    void setContext(void *context) {
        context_ = context;
    }

private:

    void on_data_available(DDSDataReader *reader) {
        ControllerCommands::Seq dataSeq;
        DDS_SampleInfoSeq infoSeq;
        DDS_ReturnCode_t rc;

        /* The following narrow function should never fail in our case, as
         * we have only one reader in the application. It simply performs
         * only a safe cast of the generic data reader into a specific
         * HelloWorldDataReader.
         */
        ControllerCommands::DataReader *helloReader = ControllerCommands::DataReader::narrow(reader);
        if (helloReader == NULL) {
            std::cerr << "! Unable to narrow data reader" << std::endl;
            return;
        }

        rc = helloReader->take(
                dataSeq,
                infoSeq,
                DDS_LENGTH_UNLIMITED,
                DDS_ANY_SAMPLE_STATE,
                DDS_ANY_VIEW_STATE,
                DDS_ANY_INSTANCE_STATE);
        if (rc == DDS_RETCODE_NO_DATA) {
            return;
        } else if (rc != DDS_RETCODE_OK) {
            std::cerr << "! Unable to take data from data reader, error "
                      << rc << std::endl;
            return;
        }

        for (int i = 0; i < dataSeq.length(); ++i) {
            if (infoSeq[i].valid_data) {
                // Process the data
                processData(dataSeq[i]);
            }
        }

        rc = helloReader->return_loan(dataSeq, infoSeq);
        if (rc != DDS_RETCODE_OK) {
            std::cerr << "! Unable to return loan, error "
                      << rc << std::endl;
        }
    }

    void processData(ControllerCommands &commands) {
        BackEnd *ptr = (BackEnd *)context_;
        std::cerr << commands.steer_angle << std::endl;
        ptr->setSteeringAngle((double)commands.steer_angle);
    }

    void* context_;
};


void *bloop(void *ctx)
{
    TwistListener *listener = new TwistListener();
    listener->setContext(ctx);
    DDSNodeInterface nodeInterface;
    nodeInterface.subscribe<ControllerCommands>("JsCommands", listener);

    DDS_Duration_t send_period = {0, 10000000};
    NDDSUtility::sleep(send_period);
    while (1) {
        NDDSUtility::sleep(send_period);
    }

#if 0
//    msg = context->messg;
//    struct Context *context = (struct Context *)ctx;
//    while (!context->exit_flag) {
////        cout << "." << endl;
//        sleep(1);
//    }
    BackEnd *ptr = (BackEnd *)ctx;
    SMController *ctrl = nullptr;

    while(1) {
        if (ctrl == nullptr) {
            ctrl = getController();
            continue;
        }

//        std::cout << "backend " << ctrl->getStatus().handwheel_angle << std::endl;
        ptr->setVelocityMPH((double)ctrl->getStatus().velocity_mph / 100.0);
        ptr->setVelocityKPH((double)ctrl->getStatus().velocity_kph / 100.0);
        ptr->setIsMoving(ctrl->getStatus().isMoving);

        switch(ctrl->getStatus().controller_state) {
            case 0:
                ptr->setVehicleState("RDG_OFF");
                break;
            case 1:
                ptr->setVehicleState("RDG_READY");
                break;
            case 2:
                ptr->setVehicleState("RDG_ON");
                break;
            case 4:
                ptr->setVehicleState("RDG_STOP");
                break;
            case 5:
                ptr->setVehicleState("RDG_DEBUG");
                break;
            default:
                break;
        }

        switch(ctrl->getStatus().controller_status_error) {
            case 0:
                ptr->setVehicleStatus(QString("OK"));
                break;
            case 1:
                ptr->setVehicleStatus(QString("CANCELLED"));
                break;
            case 2:
                ptr->setVehicleStatus(QString("UNKNOWN"));
                break;
            case 3:
                ptr->setVehicleStatus(QString("INVALID_ARGUMENT"));
                break;
            case 4:
                ptr->setVehicleStatus(QString("DEADLINE_EXCEEDED"));
                break;
            case 5:
                ptr->setVehicleStatus(QString("NOT_FOUND"));
                break;
            case 6:
                ptr->setVehicleStatus(QString("ALREADY_EXISTS"));
                break;
            case 7:
                ptr->setVehicleStatus(QString("PERMISSION_DENIED"));
                break;
            case 8:
                ptr->setVehicleStatus(QString("RESOURCE_EXHAUSTED"));
                break;
            case 9:
                ptr->setVehicleStatus(QString("FAILED_PRECONDITION"));
                break;
            case 10:
                ptr->setVehicleStatus(QString("ABORTED"));
                break;
            case 11:
                ptr->setVehicleStatus(QString("OUT_OF_RANGE"));
                break;
            case 12:
                ptr->setVehicleStatus(QString("UNIMPLEMENTED"));
                break;
            case 13:
                ptr->setVehicleStatus(QString("CRITICAL"));
                break;
            case 14:
                ptr->setVehicleStatus(QString("UNAVAILABLE"));
                break;
            case 15:
                ptr->setVehicleStatus(QString("DATA_LOSS"));
                break;
            case 16:
                ptr->setVehicleStatus(QString("RATE_EXCEEDED"));
                break;
            case 17:
                ptr->setVehicleStatus(QString("WINDOW_MISSED"));
                break;
            default:
                break;
        }

        ptr->setSteeringAngle((double)ctrl->getStatus().steering_cmd_angle);
        ptr->setHandWheelAngle((double)ctrl->getStatus().handwheel_angle / 10.0);
        ptr->setRoadWheelAngle((double)ctrl->getStatus().roadwheel_angle / 100.0);
        switch(ctrl->getStatus().steering_controller_state) {
            case 0:
                ptr->setSteeringState(QString("RDG_OFF"));
                break;
            case 1:
                ptr->setSteeringState(QString("RDG_READY"));
                break;
            case 2:
                ptr->setSteeringState(QString("RDG_ON"));
                break;
            case 4:
                ptr->setSteeringState(QString("RDG_STOP"));
                break;
            case 5:
                ptr->setSteeringState(QString("RDG_DEBUG"));
                break;
            default:
                break;
        }

        ptr->setThrottle((double)ctrl->getStatus().throttle_cmd_percentage);
        ptr->setThrottlePosition((double)ctrl->getStatus().throttle_position / 100.0);
        switch(ctrl->getStatus().throttle_controller_state) {
            case 0:
                ptr->setThrottleState(QString("RDG_OFF"));
                break;
            case 1:
                ptr->setThrottleState(QString("RDG_READY"));
                break;
            case 2:
                ptr->setThrottleState(QString("RDG_ON"));
                break;
            case 4:
                ptr->setThrottleState(QString("RDG_STOP"));
                break;
            case 5:
                ptr->setThrottleState(QString("RDG_DEBUG"));
                break;
            default:
                break;
        }

        ptr->setBrake((double)ctrl->getStatus().brake_cmd_percentage);
        ptr->setBrakePosition((double)ctrl->getStatus().brake_position / 50.0);
        switch(ctrl->getStatus().brake_controller_state) {
            case 0:
                ptr->setBrakeState(QString("RDG_OFF"));
                break;
            case 1:
                ptr->setBrakeState(QString("RDG_READY"));
                break;
            case 2:
                ptr->setBrakeState(QString("RDG_ON"));
                break;
            case 4:
                ptr->setBrakeState(QString("RDG_STOP"));
                break;
            case 5:
                ptr->setBrakeState(QString("RDG_DEBUG"));
                break;
            default:
                break;
        }

//        sleep(1);
    }
#endif

    return(NULL);
//    pthread_exit(NULL);
}

void spawnThread(void* ctx) {
    pthread_t tid;
    pthread_create(&tid, NULL, bloop, (void*)ctx);
}


BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    m_throttle = 0.0;
    m_brake = 0.0;
    m_steeringAngle = 0.0;
    m_velocityMPH = 0;
    m_velocityKPH = 0;
    m_vehicleStatus = "";
    m_vehicleState = "";
    m_steeringState = QString("");
    m_throttleState = QString("");
    m_brakeState = QString("");
    m_handWheelAngle = 0.0;
    m_roadWheelAngle = 0.0;

    m_sysInfo = QString("Plexus A3");
    
    spawnThread((void*)this);

}


void BackEnd::setThrottle(double val)
{
    if (m_throttle == val)
        return;

    m_throttle = val;
    emit throttleChanged();
}

double BackEnd::throttle()
{
    return m_throttle;
}

void BackEnd::setBrake(double val)
{
    if(m_brake == val)
        return;

    m_brake = val;
    emit brakeChanged();
}
double BackEnd::brake()
{
    return m_brake;
}

void BackEnd::setSteeringAngle(double val)
{
    if(m_steeringAngle == val)
        return;

    m_steeringAngle = val;
    emit steeringAngleChanged();
}

double BackEnd::steeringAngle()
{
    return m_steeringAngle;
}

void BackEnd::setVelocityMPH(double val)
{
    if(m_velocityMPH == val)
        return;

    m_velocityMPH = val;
    emit velocityMPHChanged();
}

double BackEnd::velocityMPH()
{
    return m_velocityMPH;
}

void BackEnd::setVelocityKPH(double val)
{
    if(m_velocityKPH == val)
        return;

    m_velocityKPH = val;
    emit velocityKPHChanged();
}

double BackEnd::velocityKPH()
{
    return m_velocityKPH;
}


void BackEnd::setVehicleStatus(QString qstring)
{
    if(m_vehicleStatus == qstring)
        return;

    m_vehicleStatus = qstring;
    emit vehicleStatusChanged();
}

QString BackEnd::vehicleStatus()
{
    return m_vehicleStatus;
}

void BackEnd::setVehicleState(QString qstring)
{
    if(m_vehicleState == qstring)
        return;

    m_vehicleState = qstring;
    emit vehicleStateChanged();
}

QString BackEnd::vehicleState()
{
    return m_vehicleState;
}

void BackEnd::setIsMoving(bool val)
{
    if(m_isMoving == val)
        return;

    m_isMoving = val;
    emit isMovingChanged();
}

bool BackEnd::isMoving()
{
    return m_isMoving;
}

void BackEnd::setSteeringState(const QString qstring) {
    if(m_steeringState == qstring)
        return;

    m_steeringState = qstring;
    emit steerStateChanged();
}

QString BackEnd::steeringState() {
    return m_steeringState;
}

void BackEnd::setThrottleState(QString qString) {
    if(m_throttleState == qString)
        return;

    m_throttleState = qString;
    emit throttleStateChanged();
}

QString BackEnd::throttleState() {
    return m_throttleState;
}

QString BackEnd::brakeState() {
    return m_brakeState;
}

void BackEnd::setBrakeState(QString qString) {
    if(m_brakeState == qString)
        return;

    m_brakeState = qString;
    emit brakeStateChanged();
}

double BackEnd::handWheelAngle() {
    return m_handWheelAngle;
}

void BackEnd::setHandWheelAngle(double val) {
    if(m_handWheelAngle == val)
        return;

    m_handWheelAngle = val;
    emit handWheelAngleChanged();
}

double BackEnd::roadWheelAngle() {
    return m_roadWheelAngle;
}

void BackEnd::setRoadWheelAngle(double val) {
    if(m_roadWheelAngle == val)
        return;

    m_roadWheelAngle = val;
    emit roadWheelAngleChanged();
}

double BackEnd::throttlePosition() {
    return m_throttlePosition;
}

void BackEnd::setThrottlePosition(double val) {
    if(m_throttlePosition == val)
        return;

    m_throttlePosition = val;
    emit throttlePositionChanged();
}

double BackEnd::brakePosition() {
    return m_brakePosition;
}

void BackEnd::setBrakePosition(double val) {
    if(m_brakePosition == val)
        return;

    m_brakePosition = val;
    emit brakePositionChanged();
}

QString BackEnd::sysInfo() {
    return m_sysInfo;
}

void BackEnd::setSysInfo(QString qString) {
    if (m_vehicleState == "READY")
        m_sysInfo = QString("READY");
}
