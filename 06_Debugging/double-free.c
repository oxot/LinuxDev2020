#include <stdio.h>
#include <stdlib.h>


int main() 
{
	int* a = malloc(10 * sizeof(int));

	for(int i = 0; i<10; i++)
	{	
		a[i] = i;
		printf("%d  \n", a[i]);
	}


	free(a);
	free(a);

	return 0;
}