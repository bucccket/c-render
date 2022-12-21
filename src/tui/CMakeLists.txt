set(UTIL_HDRS
   tui.h
)

set(UTIL_SRC
   tui.c
)

add_library(tui SHARED ${UTIL_HDRS} ${UTIL_SRC})
