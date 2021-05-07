
cmake_minimum_required(VERSION 3.5)

include(ExternalProject)

set(DICTIONARIES_DIR ${CMAKE_BINARY_DIR}/dictionaries)
add_custom_target(PullDictionaries COMMAND ${CMAKE_CURRENT_LIST_DIR}/scripts/pull_dictionaries.sh ${DICTIONARIES_DIR})

set(HUNSPELL_BUILD_DIR ${CMAKE_BINARY_DIR}/hunspell)
ExternalProject_Add(hunspell
        SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/depend/hunspell
        PREFIX ${CMAKE_CURRENT_LIST_DIR}/depend/hunspell
        BINARY_DIR ${HUNSPELL_BUILD_DIR}
        CONFIGURE_COMMAND autoreconf -vfi ${CMAKE_CURRENT_LIST_DIR}/depend/hunspell && ${CMAKE_CURRENT_LIST_DIR}/depend/hunspell/configure --prefix ${HUNSPELL_BUILD_DIR}
        BUILD_COMMAND make)

find_package(PkgConfig REQUIRED)
set(CMAKE_PREFIX_PATH ${HUNSPELL_BUILD_DIR}/lib/pkgconfig)
set(PKG_CONFIG_PATH ${HUNSPELL_BUILD_DIR}/lib/pkgconfig)
pkg_search_module(HUNSPELL REQUIRED ${HUNSPELL_BUILD_DIR}/lib/pkgconfig/hunspell.pc)

link_directories(${HUNSPELL_LIBRARY_DIRS})
add_executable(Smashable main.cpp)
message(Blah ${HUNSPELL_LIBRARIES})
target_link_libraries(Smashable PRIVATE ${HUNSPELL_LIBRARIES})
target_include_directories(Smashable PRIVATE ${HUNSPELL_INCLUDE_DIRS})
target_compile_definitions(Smashable PRIVATE -DDICTIONARIES_DIR="${DICTIONARIES_DIR}")
add_dependencies(Smashable PullDictionaries hunspell)