set(FS_HDRS
   content_loader.h
)

set(FS_SRC
   content_loader.c
)

add_library(fs ${FS_HDRS} ${FS_SRC})
