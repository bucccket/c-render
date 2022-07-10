set(UI_HDRS
   composite.h
   window.h
)

set(UI_SRC
   composite.c
   window.c
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library(ui SHARED ${UI_HDRS} ${UI_SRC})

target_link_libraries(ui ${CURSES_LIBRARY})
target_link_libraries(ui curses)
target_link_libraries(ui util)
