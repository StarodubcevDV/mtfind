
cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "mtfind_project")

project(${PROJECT_NAME} VERSION 1.0)

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
        ${CMAKE_CURRENT_SOURCE_DIR}/sources
)

target_sources(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/matches_finding.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/thread_matches_finding.cpp"
)

add_executable(mtfind "${CMAKE_CURRENT_SOURCE_DIR}/mtfind.cpp")
target_link_libraries(mtfind LINK_PUBLIC ${PROJECT_NAME} pthread)

enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)