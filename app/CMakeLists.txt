# variable with executable name
set(EXEC_NAME main)

# creates an executable
add_executable(${EXEC_NAME} main.c)

target_compile_features(${EXEC_NAME} PRIVATE c_std_11)

# links our previously defined libs
target_link_libraries(${EXEC_NAME} PRIVATE c_template)
