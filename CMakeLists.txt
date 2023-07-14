cmake_minimum_required(VERSION 3.22.1)

# MAJOR.MINOR.PATCH - used below
project(age-since-birth VERSION 0.1.0)
# Output is relative to binary directory ( build directory )
configure_file(src/utils/version.h.in ../src/utils/version.h)

# add_executable and add_library creates a TARGET
add_executable(${PROJECT_NAME} src/main.c)

# list is then used as: ${my_sources}
set(TIME_CONVERSION
	time_conversion.h
	time_conversion.c
)
list(TRANSFORM TIME_CONVERSION PREPEND "src/time_conversion/")

set(UTILS
	app_utils.h
	app_utils.c
)
list(TRANSFORM UTILS PREPEND "src/utils/")

set(VALIDATE_INPUT
	validate_input.h
	validate_input.c
)
list(TRANSFORM VALIDATE_INPUT PREPEND "src/validate_input/")

target_sources(${PROJECT_NAME} PUBLIC
	${TIME_CONVERSION}
	${UTILS}
	${VALIDATE_INPUT}
)

# adds the lib subdir to the include path so I can just include "header.h" instead of "subdir/header.h"
target_include_directories(${PROJECT_NAME} PRIVATE
	src/time_conversion
	src/utils
	src/validate_input
)
#add_subdirectory(lib) this adds a directory to the build path
#target_include_directories(${PROJECT_NAME} PUBLIC lib)
#target_link_libraries(${PROJECT_NAME} mylib) this links the built lib file that was created in the /lib subdir using a CMakeLists.txt with add_library(mylib mylib.c)

# Specify cmdline arguments for the compiler
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)
