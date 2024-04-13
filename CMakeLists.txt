cmake_minimum_required(VERSION 3.22)
project(wechat-cloud-catcher VERSION 1.0.0)

#set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set_target_properties(${PROJECT_NAME} PROPERTIES PLATFORM_TOOLSET "Intel C++ Compiler XE 12.1")
#set_target_properties(${PROJECT_NAME} PROPERTIES PLATFORM_TOOLSET "Intel C++ Compiler 2022")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -masm=intel")
#message("CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/output")
set(BUILD_opencv_world ON)

file(GLOB SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/**/*.h"
        "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#link_directories("src/include/spdlog")

#find_package(fmt CONFIG REQUIRED)
#find_package(spdlog CONFIG REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE
#        fmt::fmt
#        spdlog::spdlog
#)

add_subdirectory(
        include/fmt
        include/spdlog
)

target_include_directories(${PROJECT_NAME} PRIVATE
        include/fmt/include
        include/spdlog/include
)

#target_link_libraries(${PROJECT_NAME} PRIVATE
#        fmt
#        spdlog
#)




SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C
        RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
        LIBRARY_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/lib
        ARCHIVE_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/lib
        OUTPUT_NAME ${PROJECT_NAME}
        PREFIX "")


#target_link_libraries(${PROJECT_NAME} PRIVATE fmtd spdlogd)

#message("TARGET_FILE: ${CMAKE_BINARY_DIR}/fmtd.dll")

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:fmt>" "$<CMAKE_BINARY_DIR:${PROJECT_NAME}>"
#)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:fmtd>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
#        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:fmtd>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
#        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:spdlogd>" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
#)
