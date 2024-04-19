
#include <regex>
#include <string>


std::regex build_regex_mask(std::string input_mask);

std::vector<std::string> get_matches(std::string input, std::regex mask);
