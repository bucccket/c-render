set(UI_HDRS
   statuslabel.h
   menubar.h
   composite.h
   window.h
   ui_utils.h
)

set(UI_SRC
   statuslabel.c
   menubar.c
   composite.c
   window.c
   ui_utils.c
)

add_library(ui SHARED ${UI_HDRS} ${UI_SRC})