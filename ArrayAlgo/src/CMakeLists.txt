
add_subdirectory(ArrayLib)

add_executable (${PROJECT_NAME} "main.c")

target_include_directories(${PROJECT_NAME}
	PRIVATE "ArrayLib/"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	ArrayLib
)