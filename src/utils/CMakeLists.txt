set(UTIL_HDRS
   vector.h
   keyboard.h
   sprite_edit.h
   stringutils.h
)

set(UTIL_SRC
   vector.c
   keyboard.c
   sprite_edit.c
   stringutils.c
)

add_library(utils SHARED ${UTIL_HDRS} ${UTIL_SRC})
