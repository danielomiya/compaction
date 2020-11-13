#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

extern "C" {
#include "compaction/compaction.h"
#include "compaction/helpers.h"
}

TEST_CASE("compacts repeated characters", "[prog]") {

    SECTION("simple compaction case") {
        const char *input = "aaaaaaabbbbbaaaaaaaaaa";
        const char *expected = "a7-b5-a10";
        const char *result = prog(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("non repeated characters case") {
        const char *input = "abcabc";
        const char *expected = "a1-b1-c1-a1-b1-c1";
        const char *result = prog(input);

        REQUIRE(str_eq(result, expected));
    }

}
