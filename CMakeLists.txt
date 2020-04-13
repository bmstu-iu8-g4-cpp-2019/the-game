cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COVERAGE "Build coverage" OFF)

set(
        HUNTER_CACHE_SERVERS
        "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
        CACHE STRING "Default cache server"
)

include("tools/gate/cmake/HunterGate.cmake")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
        SHA1 "9a3594a61227967fb92159339ba326701b287b19"
)


project(the-game)
#string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
#string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
#string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")
string(APPEND CMAKE_CXX_FLAGS " -Wno-error=non-virtual-dtor")
string(APPEND CMAKE_CXX_FLAGS " -lpthread")
project(run-game)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

find_package(SFML 2 REQUIRED graphics window system)
include_directories(${SFML_INCLUDE_DIR})

add_library(the-game STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Bullet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObject.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Movable.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Player.cpp
        )
add_executable(tests
        ${CMAKE_CURRENT_SOURCE_DIR}/ut/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ut/movable-ut.cpp
        )
add_executable(run-game
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Source.cpp
        )
target_include_directories(the-game
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
target_include_directories(tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
target_include_directories(run-game
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
target_link_libraries(tests GTest::main the-game ${SFML_LIBRARIES})
target_link_libraries(the-game  ${SFML_LIBRARIES})
target_link_libraries(run-game the-game  ${SFML_LIBRARIES})
enable_testing()
add_test(NAME unit_tests COMMAND tests)

if (BUILD_COVERAGE)
    set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
    find_package(codecov)
    add_coverage(the-game)
    add_coverage(run-game)
    add_coverage(tests)
    list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
    coverage_evaluate()
endif ()
