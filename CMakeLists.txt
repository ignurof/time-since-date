cmake_minimum_required(VERSION 3.22.1)

project(age-since-birth)

add_executable(${PROJECT_NAME} src/main.c)

target_sources(${PROJECT_NAME} PRIVATE
	src/time_conversion.h
	src/time_conversion.c
)

#add_subdirectory(lib) this adds a directory to the build path
#target_include_directories(${PROJECT_NAME} PUBLIC lib) # adds the lib subdir to the include path so I can just include "header.h" instead of "subdir/header.h"
#target_link_libraries(${PROJECT_NAME} mylib) this links the built lib file that was created in the /lib subdir using a CMakeLists.txt with add_library(mylib mylib.c)

# Specify cmdline arguments for the compiler
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)
