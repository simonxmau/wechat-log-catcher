cmake_minimum_required(VERSION 3.22)
project(wlc VERSION 1.0.0)

#set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/output")

file(GLOB SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/**/*.h"
        "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

add_subdirectory(
        include/fmt
        include/spdlog
)

target_include_directories(${PROJECT_NAME} PRIVATE
        include/fmt/include
        include/spdlog/include
)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C
        RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
        LIBRARY_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/lib
        ARCHIVE_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/lib
        OUTPUT_NAME ${PROJECT_NAME}
        PREFIX "")

install(
        TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${INSTALL_DIR}
)