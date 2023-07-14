cmake_minimum_required(VERSION 3.22.1)

# MAJOR.MINOR.PATCH - used below
project(age-since-birth VERSION 0.1.0)
# Output is relative to binary directory ( build directory )
configure_file(src/utils/version.h.in ../src/utils/version.h)

# add_executable and add_library creates a TARGET
add_executable(${PROJECT_NAME} src/main.c)

# list is then used as: ${my_sources}
set(UTILS
	app_utils.h
	app_utils.c
	validate_input/validate_input.h
	validate_input/validate_input.c
	time_conversion/time_conversion.h
	time_conversion/time_conversion.c
)
list(TRANSFORM UTILS PREPEND "src/utils/")

target_sources(${PROJECT_NAME} PUBLIC
	${UTILS}
)

# adds the lib subdir to the include path so I can just include "header.h" instead of "subdir/header.h"
target_include_directories(${PROJECT_NAME} PRIVATE
	src/utils
	src/utils/validate_input
	src/utils/time_conversion
)
#add_subdirectory(lib) this adds a directory to the build path
#target_include_directories(${PROJECT_NAME} PUBLIC lib)
#target_link_libraries(${PROJECT_NAME} mylib) this links the built lib file that was created in the /lib subdir using a CMakeLists.txt with add_library(mylib mylib.c)

# Specify cmdline arguments for the compiler
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)
