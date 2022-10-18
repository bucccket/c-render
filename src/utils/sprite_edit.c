#include "sprite_edit.h"

void spriteEdit()
{
    int row, col;
    int r_old = 0, c_old = 0;

    keys key;

    setlocale(LC_CTYPE, "C-UTF-8");
    initscr();
    initKeyboard();

    adjustScreen(&row, &col, &r_old, &c_old);

    window *window = window_.new(col, row, 2, 2, "Sprite Editor");
    element *menubartest = &(element){
        .type = MENUBAR,
        .menubar = menubar_.new(window, LAYOUT_FLAG_TOP)};
    element *titlebar = &(element){
        .type = COMPOSITE,
        .composite = composite_.new(window, "titlebar", 1, 4, 20, 12, COMPOSITE_FLAG_CENTER)};
    element *options = &(element){
        .type = COMPOSITE,
        .composite = composite_.new(window, "options", 21, 4, 20, 12, COMPOSITE_FLAG_CENTER | COMPOSITE_FLAG_EXTEND_H)};
    element *info = &(element){
        .type = COMPOSITE,
        .composite = composite_.new(window, "info", 1, 16, 20, 15, COMPOSITE_FLAG_CENTER | COMPOSITE_FLAG_EXTEND_V)};
    element *status = &(element){
        .type = STATUSLABEL,
        .statuslabel = statuslabel_.new(window, "STATUS: User Interface in progress still. Also the status label render is not fully implemented yet")}; 
    element *labeltest = &(element){
        .type = LABEL,
        .label = label_.new(window,"test label", 10,30, TEXT_ORIENTATION_LEFT)};

    window->add(window, menubartest);
    window->add(window, titlebar);
    window->add(window, options);
    window->add(window, info);
    window->add(window, status);
    window->add(window, labeltest);

    while (true)
    {
        usleep(1000000 / FPS); // pass CPU time to system for n delay

        if (keyHandle(&key) != RENDER_CONTINUE)
        {
            window->destroy(window);
            endwin();
            break;
        }

        if (!adjustScreen(&row, &col, &r_old, &c_old))
        {
            window->resize(window, col, row);
            window->render(window);
        }

        refresh();
    }
}
