cmake_minimum_required(VERSION 3.19)
project(SingletonImplementation)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "C:\\Program Files\\boost\\boost_1_76_0")
link_directories("C:\\Program Files\\boost\\boost_1_76_0\\stage\\lib")

find_package(Boost)
message("Boost found: ${Boost_FOUND}")
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()
add_executable(SingletonImplementation main.cpp)

target_link_libraries(SingletonImplementation ${Boost_LIBRARIES})