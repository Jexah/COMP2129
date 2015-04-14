#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

void get_arg_from_command(char *start, int arg, char *buffer)
{
	for(int i = 0; i < arg; ++i)
	{
		if(i != arg)
		{
			start = strchr(start, ' ');
		}
	}
	while(*start != '\n' && *start != ' ' && (*buffer++ = *start++));
}

void print_todo(FILE *todo)
{
}

void populate_list(list_head *list)
{
	FILE *todo = fopen("todo.txt", "rw+");
	char buf[128];
	int current_line = 1;
	while(fgets(buf, sizeof(buf), todo))
	{
		struct list_head element;
		element->data = malloc(
		list_add(element, 
		printf("%d. %s", current_line, buf);
		current_line++;
	}
}

int main(void)
{
	struct list_head list;
	list_init(&list);


	printf("\n> ");
	
	char buf[128];
	char last_command [128];

	while(fgets(buf, sizeof(buf), stdin))
	{
		strcpy(last_command, buf);

		char arg[128] = {0};
		get_arg_from_command(buf, 0, arg);
		printf("'%s'\n", arg);
		if(strcmp(arg, "help") == 0)
		{
			printf("help, new, delete, move, undo\n");
		}
		else if(strcmp(arg, "new") == 0)
		{
			fprintf(todo, "%s", strchr(buf, ' ')+1);
		}
		else if(strcmp(arg, "move") == 0)
		{
			// move
		}
		else if(strcmp(arg, "delete") == 0)
		{
			// delete
		}
		else if(strcmp(arg, "undo") == 0)
		{
			// undo
		}
		printf("\n> ");
	}
	
    return 0;
}
