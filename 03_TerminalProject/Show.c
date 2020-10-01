#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define DX 3

int fileSize(char* path)
{
	FILE *f = fopen(path, "r");
	int c = 0;
	char ch;

	while((ch = fgetc(f)) != EOF)
		if(ch == '\n')
			c++;

	return c+1;
}

int main(int argc, char** argv) 
{
	if(argc < 2)
		return 1;
    WINDOW *win;
    int c = 0;
    int line = 0;

    initscr();
    noecho();
    cbreak();

    FILE *f = fopen(argv[1], "r");
    int size = fileSize(argv[1]);
    char ff[size][COLS-2*DX];

    for(int i = 0; i<size; i++)
    	fgets(ff[i], COLS-2*DX, f);

    printw("File: %s, size: %d", argv[1], size);
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);

    do 
    {
		if(c == 32)
			if(line < size - LINES + 2*DX + 2)
				line++;
		
		werase(win);
		wprintw(win, "\n");

    	for(int j = 0; j < LINES-2*DX-2; j++)
	    	wprintw(win, "  %d: %s", line + j, ff[line + j]);

    	box(win, 0, 0);
		wrefresh(win);
    } while((c = wgetch(win)) != 27);

    endwin();
    return 0;
}