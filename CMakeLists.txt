
cmake_minimum_required(VERSION 3.5)

add_executable(Smashable main.cpp)

# TODO hack city for now
target_link_libraries(Smashable PRIVATE ${CMAKE_CURRENT_LIST_DIR}/depend/hunspell/src/hunspell/.libs/libhunspell-1.7.a)