cmake_minimum_required(VERSION 3.22.1)

project(age-since-birth)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(lib)

target_include_directories(${PROJECT_NAME} PUBLIC lib)

target_link_libraries(${PROJECT_NAME} mylib)
