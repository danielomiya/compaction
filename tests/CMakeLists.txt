FetchContent_Declare(
    catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.3)

FetchContent_MakeAvailable(catch)

file(GLOB TEST_SOURCES "${CTemplate_SOURCE_DIR}/tests/test_*.cpp")

foreach(TEST ${TEST_SOURCES})
    # get filename without extension
    get_filename_component(TEST_NAME ${TEST} NAME_WE)

    # add executable for this test
    add_executable(${TEST_NAME} ${TEST})

    # add feature c++17 to this test
    target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)

    # links libraries so this executable can reference them
    target_link_libraries(${TEST_NAME} PRIVATE c_template Catch2::Catch2)

    # add test to be run by CTest
    add_test(NAME ${TEST_NAME}
             COMMAND ${TEST_NAME})

endforeach()
