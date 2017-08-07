cmake_minimum_required(VERSION 3.0)
project(jscontrol)

file(GLOB_RECURSE DDS_SOURCES "../CommonInfrastructure/*cxx" "../generated/*.cxx")

SET(CMAKE_CXX_FLAGS "-std=c++11 -DARCH=x64Linux3gcc4.8.2 -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -m64 ${CMAKE_CXX_FLAGS}")

find_path(
        NDDS_INCLUDE_DIRS
        ndds/ndds_c.h
        /opt/rti/include
)

find_library(
        NDDS_LIBRARIES
        NAMES nddscore libnddscore
        HINTS "/opt/rti/lib/x64Linux3gcc4.8.2"
)

include_directories(${NDDS_INCLUDE_DIRS} ${NDDS_INCLUDE_DIRS}/ndds "../generated" "../CommonInfrastructure")
set(LIBS ${LIBS} ${NDDS_LIBRARIES})

add_executable(${PROJECT_NAME}  ${DDS_SOURCES} joystick.cc JsControl.cpp G29Control.cpp F310Control.cpp JsControlMain.cpp JsControlFactory.cpp JsControlFactory.h)


target_link_libraries(${PROJECT_NAME}
        ${NDDS_LIBRARIES} -lnddscore -lnddscppd -lnddscd -lnddscored -ldl -lnsl -lm -lpthread -lrt
        )
