set(UI_HDRS
   composite.h
   window.h
)

set(UI_SRC
   composite.c
   window.c
)
add_library(ui SHARED ${UI_HDRS} ${UI_SRC})