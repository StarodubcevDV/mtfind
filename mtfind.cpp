#include <iostream>
#include <fstream>
#include <pthread.h>

#include "includes/thread_matches_finding.h"
#include "includes/matches_finding.h"


static pthread_mutex_t g_mutex;

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << "Invalid input parameters! Expected parameters: {filename} {mask}" << std::endl;
        return -1;
    }

    std::ifstream file(argv[1]);

    std::string line;
    int line_idx = 1;

    std::regex mask(build_regex_mask(argv[2]));

    int matches_count = 0;
    std::map<int, std::vector<std::string>> matches_result;
    
    if (file.is_open()) {
        while (std::getline(file, line)) 
        {
            thread_matches result_matches;
            result_matches.mask = mask;
            result_matches.line_idx = line_idx;
            result_matches.matches_count = &matches_count;
            result_matches.matches_result = &matches_result;
            result_matches.input_data = line;

            thread_find_matches(result_matches);
            line_idx++;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    std::cout << matches_count << std::endl;
    for (auto &[line, matches]: matches_result)
    {
        for (auto &match: matches)
        {
            std::cout << line << " " << match << std::endl;
        }
    }

    destroy_mutex();

    return 0;
}