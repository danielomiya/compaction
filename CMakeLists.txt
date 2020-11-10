cmake_minimum_required(VERSION 3.1)

project(CTemplate
        VERSION 0.0.1
        DESCRIPTION "Simple template for C applications with unit testing"
        LANGUAGES C CXX)

set(CMAKE_CXX_EXTENSIONS OFF)

# support for folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(CTest)

# include support to fetch, so we can add catch2 later on
include(FetchContent)

add_subdirectory(src)

add_subdirectory(app)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
