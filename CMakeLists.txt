cmake_minimum_required(VERSION 3.10)
project(WFCGenerator)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(WFCGenerator main.cpp tile.cpp tileset.cpp tilesetconfig.cpp wfc_generator.cpp grid.cpp cell.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(WFCGenerator ${OpenCV_LIBS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
  set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")
endif()