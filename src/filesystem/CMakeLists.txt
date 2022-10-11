set(FS_HDRS
   buffered_reader.h
)

set(FS_SRC
   buffered_reader.c
)

add_library(fs SHARED ${FS_HDRS} ${FS_SRC})