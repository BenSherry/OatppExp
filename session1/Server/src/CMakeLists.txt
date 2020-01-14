cmake_minimum_required(VERSION 3.7.2)

project(Server1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server1 App.cpp)

target_link_libraries(Server1
    pthread
    oatpp
)
