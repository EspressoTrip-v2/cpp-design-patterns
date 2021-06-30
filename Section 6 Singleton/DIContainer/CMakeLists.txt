cmake_minimum_required(VERSION 3.19)
project(DIContainer)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "C:\\Program Files\\boost\\boost_1_76_0")
link_directories("C:\\Program Files\\boost\\boost_1_76_0\\stage\\lib")

find_package(Boost)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()
add_executable(DIContainer main.cpp di.h)

target_link_libraries(DIContainer ${Boost_LIBRARIES})