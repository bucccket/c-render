set(GRAPHICS_HDRS
   sprite.h
   graphic.h
)

set(GRAPHICS_SRC
   sprite.c
   graphic.c
)

add_library(render ${RENDER_HDRS} ${RENDER_SRC})
