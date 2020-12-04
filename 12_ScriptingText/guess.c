/* COMMENT:: Number Guess, 0.1: Fri Dec  4 14:53:06 MSK 2020 */
#include <stdio.h>
#include <string.h>
#include "guess.h"

char* toRom (int i)
{
	return rom[i-1];
}

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

	if(argc>1)
	{
		if(!strcmp(argv[1], "-r"))
			f = 1;
	}
	if(f)	
		printf("Pick a number from I to C\n");
	else
		printf("Pick a number from 1 to 100\n");	
	
	while(1)
	{
		if(f)
			printf("Is your number greater than %s? (y/n)\n", toRom((y+x)/2));
		else
			printf("Is your number greater than %d? (y/n)\n", (y+x)/2);

		if(scanf(" %c", &c) < 0)
			return 1;

		if(c == 'y')
			x = (y+x)/2 + 1;
		else 
			if(c == 'n')
				y = (y+x)/2;
			else
			{
				printf("Incorrect input\n");
				if(scanf(" %c", &c) < 0)
					return 1;
			}

		if(x == y)
		{	
			if(f)
				printf("Your number is %s\n", toRom(x));
			else
				printf("Your number is %d\n", x);
			break;
		}
	}

	return 0;
}