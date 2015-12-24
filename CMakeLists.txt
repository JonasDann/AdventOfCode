cmake_minimum_required(VERSION 3.3)
project(AdventOfCodeC)

set(OPENSSL_INCLUDE_DIR P:/OpenSSL-Win32/include)
set(OPENSSL_LIBRARIES P:/OpenSSL-Win32/lib/MinGW)

include_directories(${OPENSSL_INCLUDE_DIR})
link_directories(${OPENSSL_LIBRARIES})

add_executable(day1-1 day1-1.c util/general.c)
add_executable(day1-2 day1-2.c util/general.c)
add_executable(day2-1 day2-1.c util/general.c util/present.c)
add_executable(day2-2 day2-2.c util/general.c util/present.c)
add_executable(day3-1 day3-1.c util/general.c util/positionVisistedList.c)
add_executable(day3-2 day3-2.c util/general.c util/positionVisistedList.c)
add_executable(day4-1 day4-1.c util/general.c)
add_executable(day4-2 day4-2.c util/general.c)
add_executable(day5-1 day5-1.c util/general.c)
add_executable(day5-2 day5-2.c util/general.c util/charPairCache.c)
add_executable(day6-1 day6-1.c util/general.c util/lightGrid.c)
add_executable(day6-2 day6-2.c util/general.c util/lightGrid.c)

target_link_libraries(day4-1 eay32)
target_link_libraries(day4-2 eay32)