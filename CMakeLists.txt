cmake_minimum_required(VERSION 3.20)
project(fluxlog VERSION 0.1.0 LANGUAGES CXX)

add_library(fluxlog STATIC 
            src/logger.cpp
            src/formatter/simple_formatter.cpp
            src/sink/console_sink.cpp
            src/sink/file_sink.cpp)

target_include_directories(fluxlog 
            PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/fluxlog>
            $<INSTALL_INTERFACE:include/fluxlog>)

target_compile_features(fluxlog PUBLIC cxx_std_20)

find_package(fmt REQUIRED)

target_link_libraries(fluxlog
                PUBLIC 
                fmt::fmt)

install(TARGETS fluxlog
        EXPORT fluxlogTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/
        DESTINATION include)

install(EXPORT fluxlogTargets
        FILE fluxlogTargets.cmake
        NAMESPACE fluxlog::
        DESTINATION lib/cmake/fluxlog)

include(CMakePackageConfigHelpers)

configure_package_config_file(
        cmake/fluxlogConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/fluxlogConfig.cmake
        INSTALL_DESTINATION lib/cmake/fluxlog
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/fluxlogConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

install(FILES 
        ${CMAKE_CURRENT_BINARY_DIR}/fluxlogConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/fluxlogConfigVersion.cmake
        DESTINATION lib/cmake/fluxlog)