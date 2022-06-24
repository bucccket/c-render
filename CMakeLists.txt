cmake_minimum_required(VERSION 3.16)
project(c-render VERSION 0.0.1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${app_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS -pg)
set(CMAKE_EXE_LINKER_FLAGS -pg)
set(CMAKE_BUILD_TYPE=Debug)

add_subdirectory(src)

add_executable(c-render src/app_main.c)

target_link_libraries(c-render utils)
target_link_libraries(c-render render)
target_link_libraries(c-render graphics)
target_link_libraries(c-render fs)

install(TARGETS c-render RUNTIME DESTINATION ${BIN_DIR})