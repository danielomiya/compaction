#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

extern "C" {
#include "compaction/compaction.h"
#include "compaction/helpers.h"
}

TEST_CASE("compacts repeated characters", "[prog]") {
    SECTION("simple compaction case") {
        const char* input = "aaaaaaabbbbbaaaaaaaaaa";
        const char* expected = "a7-b5-a10";
        const char* result = prog(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("non repeated characters case") {
        const char* input = "abcabc";
        const char* expected = "a1-b1-c1-a1-b1-c1";
        const char* result = prog(input);

        REQUIRE(str_eq(result, expected));
    }
}

TEST_CASE("uncompacts a string", "[desprog]") {
    SECTION("groups of single char compacted") {
        const char* input = "a7-b5-a10";
        const char* expected = "aaaaaaabbbbbaaaaaaaaaa";
        const char* result = desprog(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("single group of compacted chars") {
        const char* input = "ab11";
        const char* expected = "ababababababababababab";
        const char* result = desprog(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("groups of single and multiple chars compacted") {
        const char* input = "ab6-a15";
        const char* expected = "ababababababaaaaaaaaaaaaaaa";
        const char* result = desprog(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("non hyphenized groups") {
        const char* input = "abc4xy3c7";
        const char* expected = "abcabcabcabcxyxyxyccccccc";
        const char* result = desprog(input);

        REQUIRE(str_eq(result, expected));
    }
}

TEST_CASE("compacts groups of repeated characters", "[prog2]") {
    SECTION("single group of chars") {
        const char* input = "ababababababababababab";
        const char* expected = "ab11";
        const char* result = prog2(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("basic case of 2 groups") {
        const char* input = "ababababababaaaaaaaaaaaaaaa";
        const char* expected = "ab6-a15";
        const char* result = prog2(input);

        REQUIRE(str_eq(result, expected));
    }

    SECTION("complex case of groups with different lengths") {
        const char* input = "abcabcabcabcxyxyxyccccccc";
        const char* expected = "abc4-xy3-c7";
        const char* result = prog2(input);

        REQUIRE(str_eq(result, expected));
    }
}
