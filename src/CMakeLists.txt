cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Overload ${SOURCES})

target_include_directories(Overload PUBLIC ${MY_INCLUDE_DIR})