cmake_minimum_required(VERSION 3.20)
project(app LANGUAGES CXX)

find_package(fluxlog REQUIRED)
find_package(fmt REQUIRED)

add_executable(app 
                main.cpp)

target_link_libraries(app 
                PRIVATE 
                fluxlog::fluxlog)
                
target_link_libraries(app 
                PRIVATE 
                fluxlog::fluxlog)
target_compile_features(app PUBLIC cxx_std_20)