
#include <map>

#include "matches_finding.h"


typedef struct thread_matches
{
    std::regex mask;
    std::string input_data;
    int line_idx;
    int *matches_count;
    std::vector<std::string> finded_matches;
    std::map<int, std::vector<std::string>> *matches_result;
} thread_matches;


void add_match_result(thread_matches search_results);

void *match_thread(void *args);

void thread_find_matches(thread_matches search_results);

void destroy_mutex();
