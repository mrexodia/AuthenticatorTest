cmake_minimum_required(VERSION 3.10)
project(AuthenticatorTest)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(cpptotp)

add_executable(AuthenticatorTest
        AuthenticatorTest.cpp)

target_link_libraries(AuthenticatorTest cppotp)