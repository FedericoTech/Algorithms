enable_testing()

set(CMAKE_PREFIX_PATH  "C:/Program Files (x86)/googletest-distribution/")

find_package(GTest REQUIRED)

include_directories("${CMAKE_PREFIX_PATH}/include")
link_directories("${CMAKE_PREFIX_PATH}/lib")

add_executable(test1 test1.cpp)

#in order to only set include<ArrayLib.h> we need to set this directive.
target_include_directories(test1
	PRIVATE "${PROJECT_SOURCE_DIR}/src/ArrayLib/"
)


target_link_libraries(test1 PRIVATE
	gtest gtest_main
	ArrayLib
)