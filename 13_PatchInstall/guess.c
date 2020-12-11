#include <stdio.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>
#include <libgen.h>

#define _(STRING) gettext(STRING)

int main(int argc, char **argv)
{
	int x = 1, y = 100;
	char c;
	char *dir;

	dir = dirname(realpath(argv[0], NULL));
	setlocale (LC_ALL, "");
	bindtextdomain ("guess", dir);
    textdomain ("guess");

	printf(_("Pick a number from 1 to 100\n"));	

	while(1)
	{
		printf(_("Is your number greater than %d? (y/n)\n"), (y+x)/2);
		scanf(" %c", &c);

		if(c == 'y')
			x = (y+x)/2 + 1;
		else 
			if(c == 'n')
				y = (y+x)/2;
			else
			{
				printf(_("Incorrect input\n"));
				scanf("%c", &c);
			}

		if(x == y)
		{
			printf(_("Your number is %d\n"), x);
			break;
		}
	}

	return 0;
}