set(UI_HDRS
   label.h
   statuslabel.h
   menubar.h
   composite.h
   window.h
   ui_utils.h
)

set(UI_SRC
   label.c
   statuslabel.c
   menubar.c
   composite.c
   window.c
   ui_utils.c
)

add_library(ui SHARED ${UI_HDRS} ${UI_SRC})