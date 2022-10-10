set(RENDER_HDRS
   char_render.h
)

set(RENDER_SRC
   char_render.c
)

add_library(render SHARED ${RENDER_HDRS} ${RENDER_SRC})