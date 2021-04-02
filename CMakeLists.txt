cmake_minimum_required(VERSION 3.17)
project(Assignment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

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

add_library(utl SHARED
            lib/src/utility.c)

# ---------------- Exception---------------- #
add_library(excpt SHARED
            lib/src/exception.c)

target_link_libraries(excpt utl)

# ---------------- Data Structure ---------------- #
add_library(dtstrct STATIC
            lib/src/DataStruct/node.c)

target_link_libraries(dtstrct excpt)

# ---------------- Movie ---------------- #
add_library(movie STATIC
            lib/src/movie.c)

target_link_libraries(dtstrct movie)
target_link_libraries(movie excpt)

# ---------------- Database ---------------- #
add_library(db SHARED
            lib/src/Database/database.c lib/src/Database/queryParser.c)

target_link_libraries(db dtstrct)

# ================================================== EXECUTABLE ================================================== #

# ---------------- Tasks ---------------- #

add_executable(Main Tasks/Main.c)
target_link_libraries(Main db)

add_executable(Console Tasks/Console.cpp)
target_link_libraries(Main db)

add_executable(Test Tasks/Test.c)
target_link_libraries(Test db)

# ---------------- Tests ---------------- #

#add_executable(LLTest Tests/Test_LinkedList.cpp)
#target_link_libraries(LLTest gtest gtest_main)

# ================================================== MESSAGES ================================================== #

message("# ---------------- PATHS ---------------- #")
message("src:                   ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin:                   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("shared lib dir:        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
