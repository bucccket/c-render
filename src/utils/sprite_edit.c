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

    window *window = window_.new(col, row, "Sprite Editor");
    composite *titlebar = composite_.new(window, "titlebar", 0, 0, 20, 20, COMPOSITE_FLAG_CENTER);
    composite *options = composite_.new(window, "options", 20, 0, 20, 20, COMPOSITE_FLAG_CENTER | COMPOSITE_FLAG_EXTEND_H);
    composite *info = composite_.new(window, "info", 0, 20, 20, 20, COMPOSITE_FLAG_CENTER | COMPOSITE_FLAG_EXTEND_V);
    window->addComposite(window, titlebar);
    window->addComposite(window, options);
    window->addComposite(window, info);

    while (true)
    {
        usleep(1000000 / FPS); // pass over CPU time while frame is paused

        window->render(window);

        if (keyHandle(&key) != RENDER_CONTINUE)
        {
            window->destroy(window);
            endwin();
            break;
        }

        if (!adjustScreen(&row, &col, &r_old, &c_old))
        {
            refresh();
        }
    }
}