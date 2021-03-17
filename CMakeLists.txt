cmake_minimum_required(VERSION 3.17)
project(Assignment)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== INCLUDES ================================================== #

# ---------------- Library Headers ---------------- #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

# ---------------- Google Test ---------------- #
add_subdirectory(lib/googletest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/include)

# ================================================== PATHS ================================================== #

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})


# ================================================== LIBRARY ================================================== #

# ---------------- Exception---------------- #
add_library(excpt SHARED
            lib/src/exception.c)

# ---------------- Movie ---------------- #
add_library(movie SHARED
            lib/src/movie.c)

target_link_libraries(movie excpt)
# ---------------- Data Structure ---------------- #
add_library(dtstrct SHARED
            lib/src/DataStruct/node.c)

target_link_libraries(dtstrct movie)

# ================================================== EXECUTABLE ================================================== #

# ---------------- Tasks ---------------- #

add_executable(MovieDatabase Tasks/MovieDatabase.c)
target_link_libraries(MovieDatabase dtstrct)

# ---------------- Tests ---------------- #

#add_executable(LLTest Tests/Test_LinkedList.cpp)
#target_link_libraries(LLTest gtest gtest_main)

# ================================================== MESSAGES ================================================== #

message("# ---------------- PATHS ---------------- #")
message("src:                   ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin:                   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("shared lib dir:        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
