cmake_minimum_required(VERSION 3.0)
project(design-pattern)

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

execute_process(COMMAND mkdir -pv ${CMAKE_SOURCE_DIR}/generated)
execute_process(COMMAND /opt/rti/bin/rtiddsgen -d ${CMAKE_SOURCE_DIR}/generated ${CMAKE_SOURCE_DIR}/idl/GamePad.idl -replace -language C++)


add_subdirectory(jscontrol)
add_subdirectory(qtgui)
add_subdirectory(vehicle)
