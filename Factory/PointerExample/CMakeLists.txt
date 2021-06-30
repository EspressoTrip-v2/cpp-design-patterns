cmake_minimum_required(VERSION 3.19)
project(PointerExample)

set(CMAKE_CXX_STANDARD 14)

add_executable(PointerExample main.cpp)




find_package(Boost)
include_directories("B:\\Coding Languages\\C++\\Standard C++\\Boost Library\\boost_1_76_0")
target_link_libraries(PointerExample ${Boost_LIBRARIES})