# set HEADERS to the files that matches the regex path
# flag CONFIGURE_DEPENDS forces CMake to regen the build system
file(GLOB HEADERS CONFIGURE_DEPENDS "${CTemplate_SOURCE_DIR}/includes/c_template/*.h")

file(GLOB SOURCES CONFIGURE_DEPENDS "${CTemplate_SOURCE_DIR}/src/*.c")

# creates a library so it can be references elsewhere
add_library(c_template ${SOURCES} ${HEADERS})

# make headers available for whoever references it
target_include_directories(c_template PUBLIC ../includes)

target_compile_features(c_template PUBLIC c_std_11)

# source group for IDEs
source_group(
    TREE "${PROJECT_SOURCE_DIR}/includes"
    PREFIX "Headers"
    FILES ${HEADERS})
