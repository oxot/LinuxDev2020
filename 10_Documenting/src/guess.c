/** @file
 */

#include <stdio.h>
#include <string.h>
#include "guess.h"
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

#define MANUAL _("Pick a number from 1 to 100 and answer the questions until the number is guessed\n\
\n\
Usage: guess [OPTION]\n\
\n\
    --help		print this help, then exit\n\
    --version	print version number, then exit\n\
\n\
")
#define VERSION "0.0"

/**
 * Convert Arabic @p i to Roman
 *
 * @param i The number to convert
 *
 * @returns The Roman number equivalent
 *
 */
char* toRom (int i)
{
	return rom[i-1];
}

/**
 * Convert @p c from Roman to Arabic
 *
 * @param c The number to convert
 *
 * @returns The Arabic number equivalent
 *
 */
int fromRom(char *c)
{
	for(int i = 0; i < 100; i++) 
	{
		if(!strcmp(c, rom[i]))
			return i + 1;
	}
	return -1;
}

int main(int argc, char** argv)
{
	int x = 1, y = 100;
	char c;
	int f = 0;

	setlocale (LC_ALL, "");
	bindtextdomain ("guess", ".");
    textdomain ("guess");

	if(argc>1)
	{
		if(!strcmp(argv[1], "-r"))
			f = 1;
		else if(!strcmp(argv[1], "--help"))
			return !printf("%s\n", MANUAL);
		else if(!strcmp(argv[1], "--version"))
			return !printf("guess %s\n", VERSION);
	}
	if(f)	
		printf(_("Pick a number from I to C\n"));
	else
		printf(_("Pick a number from 1 to 100\n"));	
	
	while(1)
	{
		if(f)
			printf(_("Is your number greater than %s? (y/n)\n"), toRom((y+x)/2));
		else
			printf(_("Is your number greater than %d? (y/n)\n"), (y+x)/2);

		if(scanf(" %c", &c) < 0)
			return 1;

		if(c == 'y')
			x = (y+x)/2 + 1;
		else 
			if(c == 'n')
				y = (y+x)/2;
			else
			{
				printf(_("Incorrect input\n"));
				if(scanf(" %c", &c) < 0)
					return 1;
			}

		if(x == y)
		{	
			if(f)
				printf(_("Your number is %s\n"), toRom(x));
			else
				printf(_("Your number is %d\n"), x);
			break;
		}
	}

	return 0;
}