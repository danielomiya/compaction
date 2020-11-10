#define CATCH_CONFIG_MAIN
#include <string.h>
#include "catch2/catch.hpp"

extern "C" {
#include "c_template/hello.h"
}

TEST_CASE("Quick check", "[hello]") {
    const char *name = "catch2";
    const char *greeting = hello(name);

    REQUIRE(strcmp(greeting, "hello, catch2") == 0);
}
