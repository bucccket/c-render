set(RENDER_HDRS
   char_render.h
)

set(RENDER_SRC
   char_render.c
)

add_library(render SHARED ${RENDER_HDRS} ${RENDER_SRC})

target_link_libraries(render ncurses)
target_link_libraries(render util)
