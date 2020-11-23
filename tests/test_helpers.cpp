#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// use extern keyword so the linker can find our functions
extern "C" {
#include "compaction/helpers.h"
}

TEST_CASE("str_eq should return true when strings are equal, otherwise false",
          "[str_eq]") {
    SECTION("strings with same content") { REQUIRE(str_eq("same", "same")); }

    SECTION("strings are different") { REQUIRE_FALSE(str_eq("diff", "same")); }
}

TEST_CASE(
    "str_ne should return true when strings are different, otherwise false",
    "[str_ne]") {
    SECTION("different strings") { REQUIRE(str_ne("a", "b")); }

    SECTION("same string content") { REQUIRE_FALSE(str_ne("same", "same")); }
}
