set(GRAPHICS_HDRS
   sprite.h
   graphic.h
)

set(GRAPHICS_SRC
   sprite.c
   graphic.c
)

add_library(graphics SHARED ${GRAPHICS_HDRS} ${GRAPHICS_SRC})
