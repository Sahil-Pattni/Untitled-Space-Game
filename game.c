#include <ncurses.h>

/* Define Item Chars */
#define PLAYER '*'
#define EMPTY ' '
#define BOLT '|'

/* Declare Functions */
void drawmap();
int main()
{	
    int y, x;               /* Co-ordinates */
    int ch;

    /* Setup Curses */
	initscr();              /* Start curses mode 		  */
    keypad(stdscr, TRUE);   /* Allows keyboard input (i.e. arrows) */
    cbreak();               /* Takes in one char at a time, no line buffer */
    noecho();               /* Doesn't echo back user input */

    clear();                /* Clears the terminal screen */

    /* Initialize Map */
    drawmap();

    /* Start Player at lower left */
    y = LINES - 1;
    x = 0;

    mvaddch(20,20,BOLT);
    do {
        mvaddch(y, x, PLAYER);
        move(y,x);
        refresh();

        ch = getch();

        switch(ch) {
            case KEY_LEFT:
                if (x > 0) {
                    mvaddch(y,x,EMPTY);
                    x--;
                }
                break;
            case KEY_RIGHT:
                if (x < COLS - 1) {
                    mvaddch(y,x,EMPTY);
                    x++;
                }
                break;
            case KEY_UP:
                if (y > 0) {
                    mvaddch(y,x,EMPTY);
                    y--;
                }
                break;
            case KEY_DOWN:
                if (y < LINES - 1) {
                    mvaddch(y,x,EMPTY);
                    y++;
                }
                break;
        }
    }
    while ((ch != 'q') && (ch != 'Q'));

	endwin();			    /* End curses mode		  */
    exit(0);                /* Exit with no error   */
    return 0;
}

void drawmap() {
    int y, x;

    /* background */

    for (y = 0; y < LINES; y++)
        mvhline(y, 0, EMPTY, COLS);
}
