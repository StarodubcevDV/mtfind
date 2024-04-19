
#include <gtest/gtest.h>
#include <string>
#include <regex>
#include <fstream>

#include "matches_finding.h"


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

    ASSERT_EQ(result, "1 Hello, 25 Hello! ");
}

TEST(MTFIND, GetMatchesFromFile)
{
    std::ifstream file("../example_data/test_data.txt");
    std::string line;

    std::regex mask(build_regex_mask("?ad"));
    std::string result = "";

    int line_idx = 1;
    int matches_count = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) 
        {
            auto matches = get_matches(line, mask);
            matches_count += matches.size();
            
            for (auto &match: matches)
            {
                result.append(std::to_string(line_idx));
                result.append(" ");
                result.append(match);
                result.append("\n");
            }
            line_idx++;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    std::string mathces_info = std::to_string(matches_count);
    mathces_info.append("\n");
    result.insert(0, mathces_info);

    ASSERT_EQ(result, "3\n5 5 bad\n6 6 mad\n7 6 had\n");
}
