
#include <gtest/gtest.h>
#include <string>
#include <regex>

#include "mask_handling.h"


TEST(MTFIND, MaskBuilding)
{
    std::string test_string = "Hello, mtfind programm";
    std::regex mask = build_regex_mask("?amm");

    auto matches = get_matches(test_string, mask);

    ASSERT_EQ(matches.size(), 1);
}

TEST(MTFIND, ComplicatedMaskBuilding)
{
    std::string test_string = "bad!, mad4, dadg";
    std::regex mask = build_regex_mask("?ad?");

    auto matches = get_matches(test_string, mask);

    ASSERT_EQ(matches.size(), 3);
}

TEST(MTFIND, GetMatchesNumber)
{
    std::string test_string = "Hello, mtfind programm";
    std::regex mask("(.?)(amm)");

    auto matches = get_matches(test_string, mask);

    ASSERT_EQ(matches.size(), 1);
}

TEST(MTFIND, PrintMatches)
{
    std::string test_string = "Hello, mtfind programm! Hello! World!";
    std::regex mask("(Hello)(.?)");

    auto matches = get_matches(test_string, mask);

    std::string result = "";
    for (auto &match: matches)
    {
        result.append(match);
        result.append(" ");
    }

    ASSERT_EQ(result, "0 Hello, 24 Hello! ");
}
