#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double throttle READ throttle WRITE setThrottle NOTIFY throttleChanged)
    Q_PROPERTY(double brake READ brake WRITE setBrake NOTIFY brakeChanged)
    Q_PROPERTY(double throttlePosition READ throttlePosition WRITE setThrottlePosition NOTIFY throttlePositionChanged)
    Q_PROPERTY(double brakePosition READ brakePosition WRITE setBrakePosition NOTIFY brakePositionChanged)
    Q_PROPERTY(double steeringAngle READ steeringAngle WRITE setSteeringAngle NOTIFY steeringAngleChanged)
    Q_PROPERTY(double handWheelAngle READ handWheelAngle WRITE setHandWheelAngle NOTIFY handWheelAngleChanged)
    Q_PROPERTY(double roadWheelAngle READ roadWheelAngle WRITE setRoadWheelAngle NOTIFY roadWheelAngleChanged)
    Q_PROPERTY(double velocityMPH READ velocityMPH WRITE setVelocityMPH NOTIFY velocityMPHChanged)
    Q_PROPERTY(double velocityKPH READ velocityKPH WRITE setVelocityKPH NOTIFY velocityKPHChanged)
    Q_PROPERTY(double velocitySetPoint READ velocitySetPoint WRITE setVelocitySetPoint NOTIFY velocitySetPointChanged)
    Q_PROPERTY(double velocityError READ velocityError WRITE setVelocityError NOTIFY velocityErrorChanged)
    Q_PROPERTY(double proportionalGain READ proportionalGain WRITE setProportionalGain NOTIFY proportionalGainChanged)
    Q_PROPERTY(double integralGain READ integralGain WRITE setIntegralGain NOTIFY integralGainChanged)
    Q_PROPERTY(double integralEffort READ integralEffort WRITE setIntegralEffort NOTIFY integralEffortChanged)
    Q_PROPERTY(QString vehicleStatus READ vehicleStatus WRITE setVehicleStatus NOTIFY vehicleStatusChanged)
    Q_PROPERTY(QString vehicleState READ vehicleState WRITE setVehicleState NOTIFY vehicleStateChanged)
    Q_PROPERTY(QString steeringState READ steeringState WRITE setSteeringState NOTIFY steerStateChanged)
    Q_PROPERTY(QString throttleState READ throttleState WRITE setThrottleState NOTIFY throttleStateChanged)
    Q_PROPERTY(QString brakeState READ brakeState WRITE setBrakeState NOTIFY brakeStateChanged)
    Q_PROPERTY(QString sysInfo READ sysInfo WRITE setSysInfo NOTIFY sysInfoChanged)
    Q_PROPERTY(bool isMoving READ isMoving WRITE setIsMoving NOTIFY isMovingChanged)
    Q_PROPERTY(bool isControllerOn READ isControllerOn WRITE setIsControllerOn NOTIFY isControllerOnChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    double throttle();
    void setThrottle(double val);

    double brake();
    void setBrake(double val);

    double throttlePosition();
    void setThrottlePosition(double val);

    double brakePosition();
    void setBrakePosition(double val);

    double steeringAngle();
    void  setSteeringAngle(double val);

    double handWheelAngle();
    void  setHandWheelAngle(double val);

    double roadWheelAngle();
    void  setRoadWheelAngle(double val);

    double velocityMPH();
    void setVelocityMPH(double val);

    double velocityKPH();
    void setVelocityKPH(double val);

    double velocitySetPoint();
    void setVelocitySetPoint(double val);

    double proportionalGain();
    void setProportionalGain(double val);

    double integralGain();
    void setIntegralGain(double val);

    double integralEffort();
    void setIntegralEffort(double val);

    double velocityError();
    void setVelocityError(double val);

    bool isControllerOn();
    void setIsControllerOn(bool val);

    QString vehicleStatus();
    void setVehicleStatus(QString qstring);

    QString vehicleState();
    void setVehicleState(QString qstring);

    bool isMoving();
    void setIsMoving(bool val);

    QString steeringState();
    void setSteeringState(const QString qstring);

    QString throttleState();
    void setThrottleState(QString qString);

    QString brakeState();
    void setBrakeState(QString qString);

    QString sysInfo();
    void setSysInfo(QString qString);

    signals:
    void throttleChanged();
    void brakeChanged();
    void throttlePositionChanged();
    void brakePositionChanged();
    void steeringAngleChanged();
    void handWheelAngleChanged();
    void roadWheelAngleChanged();
    void velocityMPHChanged();
    void velocityKPHChanged();
    void vehicleStatusChanged();
    void vehicleStateChanged();
    void isMovingChanged();
    void steerStateChanged();
    void throttleStateChanged();
    void brakeStateChanged();
    void sysInfoChanged();
    void velocitySetPointChanged();
    void velocityErrorChanged();
    void proportionalGainChanged();
    void integralGainChanged();
    void integralEffortChanged();
    void isControllerOnChanged();

private:
    double m_throttle;
    double m_brake;
    double m_steeringAngle;
    double m_velocityMPH;
    double m_velocityKPH;
    double m_handWheelAngle;
    double m_roadWheelAngle;
    double m_throttlePosition;
    double m_brakePosition;
    double m_velocitySetPoint;
    double m_velocityError;
    double m_proportionalGain;
    double m_integralGain;
    double m_integralEffort;
    bool m_isMoving;
    bool m_isControllerOn;
    QString m_vehicleStatus;
    QString m_vehicleState;
    QString m_steeringState;
    QString m_throttleState;
    QString m_brakeState;
    QString m_sysInfo;
};

#endif // BACKEND_H
