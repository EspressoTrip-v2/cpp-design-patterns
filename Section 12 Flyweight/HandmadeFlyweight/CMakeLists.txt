cmake_minimum_required(VERSION 3.19)
project(HandmadeFlyweight)

set(CMAKE_CXX_STANDARD 17)


# Set the boost root variable
set(BOOST_ROOT "C:\\Program Files\\boost\\boost_1_76_0")
include_directories("C:\\Program Files\\boost\\boost_1_76_0\\libs")

find_package(Boost)
message("Boost found: ${Boost_FOUND}")
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

add_executable(HandmadeFlyweight main.cpp)


# Link the library to target application
target_link_libraries(HandmadeFlyweight ${Boost_LIBRARIES})