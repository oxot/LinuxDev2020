#include <glib.h>
#include <stdio.h>
#include <string.h>

void iterator(gpointer key, gpointer value, gpointer user_data)
{
	printf(user_data, key, (int*)value);
}

gint comp(gconstpointer a, gconstpointer b)
{
	return b - a;
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

gboolean finder(gpointer key, gpointer value, gpointer user_data) 
{
	return (GPOINTER_TO_INT(value) == GPOINTER_TO_INT(user_data));
//		printf("-> %s:  %d\n", (char*)key, (int *)value);
}

int main(void) 
{
	FILE *f = fopen("in.txt", "r");
	char str[80*sizeof(char)];
	gchar **gl;
	GList * list = NULL, *item;

	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

	while(fgets(str, 80, f) != NULL)
	{
		gl = g_strsplit (str, " ", 80);
		for( int i = 0; i < siz((char **)gl); i++)
			g_hash_table_insert(hash, gl[i], g_hash_table_lookup(hash, gl[i]) + 1);

	}

	g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %d\n");
	printf("\n");

	list = g_list_alloc();	
	list = g_hash_table_get_values(hash);
	list = g_list_sort (list, (GCompareFunc)comp);

	for(item = list; item; item = item->next)
	{
	    printf("-> %s:  %d\n", /*(char*)g_hash_table_find(hash, (GHRFunc)finder, item->data)*/" ", GPOINTER_TO_INT(item->data));
    	
	}
//	g_list_foreach(list, (GFunc)iprint, hash);
	g_hash_table_destroy(hash);
	g_strfreev(gl); 
	fclose(f);

	return 0;
}