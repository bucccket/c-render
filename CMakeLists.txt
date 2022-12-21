cmake_minimum_required(VERSION 3.16)
project(c-render VERSION 0.0.1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${app_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} i-O0 -O2 -fno-omit-frame-pointer -fsanitize=address -fsanitize=thread -g")
set(CMAKE_CXX_FLAGS -pg)
set(CMAKE_EXE_LINKER_FLAGS -pg)
set(CMAKE_BUILD_TYPE=Debug)

add_subdirectory(src)
include_directories(src)

add_executable(c-render src/app_main.c)

#demo only
#add_executable(c-render src/utils/pd_demo/pd_demo.c)
#add_executable(c-render src/utils/pd_demo/rain_demo.c)
#add_executable(c-render src/utils/pd_demo/tuidemo.c)

#ZLIB
find_package(ZLIB REQUIRED)
target_link_libraries(c-render z)

#CURSES
set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
target_link_libraries(c-render ncursesw)

#THREADS
find_package(Threads REQUIRED)
target_link_libraries(c-render ${CMAKE_THREAD_LIBS_INIT})

#SOURCE 
target_link_libraries(c-render utils ncursesw)
target_link_libraries(c-render render ncursesw)
target_link_libraries(c-render graphics)
target_link_libraries(c-render fs z)
target_link_libraries(c-render tui)

#demo only
#target_link_libraries(c-render pd_demo tui)

target_compile_options(c-render PRIVATE -fsanitize=address)
target_link_options(c-render PRIVATE -fsanitize=address)
add_compile_options(-fsanitize=address -Wextra)
add_link_options(-fsanitize=address)

install(TARGETS c-render RUNTIME DESTINATION ${BIN_DIR})

add_custom_target(run
    COMMAND bin/c-render
    DEPENDS bin/c-render
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
