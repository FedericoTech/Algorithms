
add_subdirectory(ArrayLib)

add_executable (${PROJECT_NAME} "main.c")

#not needed here because the path is in the include in main.c
#target_include_directories(${PROJECT_NAME}
#	PRIVATE "ArrayLib/"
#)

target_link_libraries(${PROJECT_NAME} PRIVATE
	ArrayLib
)