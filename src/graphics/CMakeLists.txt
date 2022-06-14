set(GRAPHICS_HDRS
   sprite.h
   graphic.h
)

set(GRAPHICS_SRC
   sprite.c
   graphic.c
)

add_library(graphics ${GRAPHICS_HDRS} ${GRAPHICS_SRC})
