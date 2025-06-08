cmake_minimum_required(VERSION 3.31)
project(test)
find_package(OpenSSL REQUIRED)
set(CMAKE_CXX_STANDARD 20)

add_executable(test httplib.h main.cpp)

target_link_libraries(test PRIVATE OpenSSL::SSL OpenSSL::Crypto)
