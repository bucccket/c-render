set(RENDER_HDRS
   char_render.h
)

set(RENDER_SRC
   char_render.c
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library(render SHARED ${RENDER_HDRS} ${RENDER_SRC})

target_link_libraries(render ${CURSES_LIBRARY})
target_link_libraries(render curses)
target_link_libraries(render util)