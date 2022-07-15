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
    composite *titlebar = composite_.new(window, "titlebar", 1, 1, 20, 15, COMPOSITE_FLAG_CENTER);
    composite *options = composite_.new(window, "options", 21, 1, 20, 15, COMPOSITE_FLAG_CENTER | COMPOSITE_FLAG_EXTEND_H);
    composite *info = composite_.new(window, "info", 1, 16, 20, 15, COMPOSITE_FLAG_CENTER | COMPOSITE_FLAG_EXTEND_V);
    window->addComposite(window, titlebar);
    window->addComposite(window, options);
    window->addComposite(window, info);

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