set(FS_HDRS
   content_loader.h
   buffered_reader.h
)

set(FS_SRC
   content_loader.c
   buffered_reader.c
)

add_library(fs ${FS_HDRS} ${FS_SRC})
