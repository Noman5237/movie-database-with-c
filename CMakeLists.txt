cmake_minimum_required(VERSION 3.17)
project(Assignment)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== INCLUDES ================================================== #

# ---------------- Library Headers ---------------- #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

# ================================================== PATHS ================================================== #

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(CMAKE_PROJECT_DATABASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources/database)


# ================================================== LIBRARY ================================================== #

add_library(utl SHARED
            lib/src/utility.c)

# ---------------- Exception---------------- #
add_library(excpt SHARED
            lib/src/exception.c)

target_link_libraries(excpt utl)

# ---------------- Data Structure ---------------- #
add_library(dtstrct SHARED
            lib/src/DataStruct/node.c)

target_link_libraries(dtstrct excpt)

# ---------------- Input ---------------- #
add_library(input SHARED
            lib/src/input.c)

target_link_libraries(input excpt)

# ---------------- Movie ---------------- #
add_library(movie SHARED
            lib/src/movie.c)

target_link_libraries(dtstrct movie)
target_link_libraries(movie excpt)

# ---------------- Database ---------------- #
add_library(db SHARED
            lib/src/Database/database.c lib/src/Database/queryParser.c)

target_link_libraries(db dtstrct)

# ================================================== EXECUTABLE ================================================== #

# ---------------- Tasks ---------------- #

if (${CMAKE_VERSION} STRLESS 3.17)
	add_definitions(-DDATABASE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources/database/")
else ()
	add_compile_definitions(DATABASE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources/database/")
endif ()
add_executable(Main Tasks/Main.c)
target_link_libraries(Main db)

add_executable(DatabaseApp Tasks/MovieDatabaseApp.c)
target_link_libraries(DatabaseApp db)
target_link_libraries(DatabaseApp input)

add_executable(Test Tasks/Test.c)
target_link_libraries(Test db)
target_link_libraries(Test input)

# ---------------- Tests ---------------- #

#add_executable(LLTest Tests/Test_LinkedList.cpp)
#target_link_libraries(LLTest gtest gtest_main)

# ================================================== MESSAGES ================================================== #

message("# ---------------- PATHS ---------------- #")
message("src:                   ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin:                   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("shared lib dir:        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("database dir  :        ${CMAKE_PROJECT_DATABASE_DIRECTORY}")
