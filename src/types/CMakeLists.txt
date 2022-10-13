set(FS_HDRS
   vector.h
)

set(FS_SRC
   vector.c
)

add_library(types SHARED ${FS_HDRS} ${FS_SRC})
