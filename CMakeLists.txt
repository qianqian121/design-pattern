cmake_minimum_required(VERSION 2.8.2)
project (design-pattern)

SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

add_executable(${PROJECT_NAME} JsControl.cpp)
target_link_libraries(${PROJECT_NAME}

        )
