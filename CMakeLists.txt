cmake_minimum_required(VERSION 3.18)
project(c-render VERSION 0.0.1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${app_SOURCE_DIR}/cmake")

add_subdirectory(src)

add_executable(c-render src/app_main.c)

target_link_libraries(c-render utils)
target_link_libraries(c-render render)

install(TARGETS c-render RUNTIME DESTINATION ${BIN_DIR})
