
#include "mask_handling.h"

#include <iostream>


std::regex build_regex_mask(std::string input_mask)
{
    std::string tmp_mask = "(";

    for (char symbol: input_mask)
    {
        if (symbol == '?')
        {
            tmp_mask.append(".?)(");
        }
        else
        {
            tmp_mask.push_back(symbol);
        }
        
    }
    tmp_mask.append(")");

    return std::regex(tmp_mask);
}

std::vector<std::string> get_matches(std::string input, std::regex mask)
{
    std::vector<std::string> matches{};
    std::smatch match;
    std::string match_info;
    int index = 1;

    while (std::regex_search(input, match, mask))
    {
        match_info = "";
        match_info.append(std::to_string(match.position() + index));
        match_info.append(" ");
        match_info.append(match.str());
        index += match.length();

        matches.push_back(match_info);

        input = match.suffix().str();
    }
    
    return matches;
}
