set(UI_HDRS
   ui_utils.h
   menubar.h
   composite.h
   window.h
)

set(UI_SRC
   ui_utils.c
   menubar.c
   composite.c
   window.c
)

add_library(ui SHARED ${UI_HDRS} ${UI_SRC})