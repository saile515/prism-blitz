cmake_minimum_required(VERSION 3.28)

project("prism-blitz" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

list(APPEND PROJECT_SOURCES src/main.cpp)
list(APPEND PROJECT_HEADERS)
list(APPEND PROJECT_INCLUDE_DIRECTORIES ~/.local/include)
list(APPEND PROJECT_LIBRARIES coral-engine)

add_library(coral-engine SHARED IMPORTED)
set_target_properties(
  coral-engine PROPERTIES IMPORTED_LOCATION
                          /home/saile515/.local/lib/libcoral-engine.so)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${PROJECT_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIBRARIES})
