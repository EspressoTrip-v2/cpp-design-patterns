cmake_minimum_required(VERSION 3.19)
project(PrototypeSerialization)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "C:\\Program Files\\boost\\boost_1_76_0") # Set boost root
link_directories("C:\\Program Files\\boost\\boost_1_76_0\\stage\\lib") # Add the linker directory for the libraries

find_package(Boost)
message("Boost Found: ${Boost_FOUND}")
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR}) # Include the boost directory in includes
endif ()

add_executable(PrototypeSerialization main.cpp)

target_link_libraries(PrototypeSerialization ${Boost_LIBRARIES})