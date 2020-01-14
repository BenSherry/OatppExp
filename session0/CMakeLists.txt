cmake_minimum_required(VERSION 3.7.2)

project(Session1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Session1 main.cpp)

target_link_libraries(Session1
    pthread
    oatpp
)
