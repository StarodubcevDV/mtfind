

#include "thread_matches_finding.h"

pthread_mutex_t g_mutex;

void add_match_result(thread_matches search_results)
{
    pthread_mutex_lock(&g_mutex);

    (*(search_results.matches_result))[search_results.line_idx] = search_results.finded_matches;
    *(search_results.matches_count) += search_results.finded_matches.size();

    pthread_mutex_unlock(&g_mutex);
}

void *match_thread(void *args)
{
    thread_matches thread_matches = *((struct thread_matches *)args);
    char *ret;
    auto matches = get_matches(thread_matches.input_data, thread_matches.mask);
    thread_matches.finded_matches = matches;
    add_match_result(thread_matches);
    pthread_exit(ret);
}

void thread_find_matches(thread_matches search_results)
{
    pthread_t thread;
    void *tmp_search_results = (void *)&search_results;
    int result = pthread_create(&thread, NULL, match_thread, tmp_search_results);
    if (result != 0) 
    {
        throw std::runtime_error("Failed to create thread!");
    }
    pthread_join(thread, NULL);
} 

void destroy_mutex()
{
    pthread_mutex_destroy(&g_mutex);
}