set(UTIL_HDRS
   keyboard.h
   stringutils.h
)

set(UTIL_SRC
   keyboard.c
   stringutils.c
)

add_library(utils SHARED ${UTIL_HDRS} ${UTIL_SRC})
