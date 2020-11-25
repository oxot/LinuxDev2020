#include <glib.h>
#include <stdio.h>
#include <string.h>

void iterator(gpointer key, gpointer value, gpointer user_data)
{
	printf(user_data, key, (int*)value);
}

int siz(char** s)
{
	int c = 0;
	int j = 0;
	while(strcmp(s[j],"\n") != 0)
	{
		c++;
		j++;
	}
	return c;
}

int main(void) 
{
	FILE *f = fopen("in.txt", "r");
	char str[80*sizeof(char)];
	gchar **gl;

	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

	while(fgets(str, 80, f) != NULL)
	{
		gl = g_strsplit (str, " ", 80);
		for( int i = 0; i < siz((char **)gl); i++)
			g_hash_table_insert(hash, gl[i], g_hash_table_lookup(hash, gl[i]) + 1);

	}

	g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %d\n");	

//	printf("%d\n", (int)g_hash_table_lookup(hash, "ad"));// Richmond

	g_hash_table_destroy(hash);
	g_strfreev(gl); 
	fclose(f);

	return 0;
}