cmake_minimum_required(VERSION 3.0)
project(qtcontrol)

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

set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} qtquick2applicationviewer)

find_package(Qt5 COMPONENTS Quick Core Network)
qt5_add_resources(RESOURCES qml/qt-quick/qml.qrc)

add_executable(${PROJECT_NAME} qtmain.cpp backend.cpp ${RESOURCES} ${SOURCE_FILES} ${DDS_SOURCES})

qt5_use_modules(${PROJECT_NAME} Quick Core Network)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Qml Qt5::Quick
        pthread
        ${NDDS_LIBRARIES} -lnddscore -lnddscppd -lnddscd -lnddscored -ldl -lnsl -lm -lpthread -lrt
        )
