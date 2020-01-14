cmake_minimum_required(VERSION 3.7.2)

project(Client1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Client1 App.cpp)

target_link_libraries(Client1
    pthread
    oatpp
)