#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

#define MAX_LINE_LEN 128

char *get_pointer_to_arg(char *start, int arg)
{
	for(int i = 0; i < arg; ++i)
	{
		if(i != arg)
		{
			start = strchr(start, ' ')+1;
		}
	}
	return start;
}

char *get_arg_from_command(char *start, int arg)
{
	char *buffer = calloc(strlen(start), 1);
	char *rolling = buffer;
	start = get_pointer_to_arg(start, arg);
	while(*start != '\n' && *start != ' ' && (*rolling++ = *start++));
	return buffer;
}

void strcpy_no_newline(char *dst, char *src)
{
	while(*src != '\n' && (*dst++ = *src++));
}

void print_list(struct list_head *head_ptr)
{
	int current_line = 1;
	printf("%d. %s\n", current_line, head_ptr->data);
	struct list_head *current_ptr = head_ptr->next;
	while(current_ptr != head_ptr)
	{
		current_line++;
		printf("%d. %s\n", current_line, current_ptr->data);
		current_ptr = current_ptr->next;
	}
}

void populate_list(struct list_head *head_ptr)
{
	static int head_initialized = 0;
	FILE *todo = fopen("todo.txt", "r");
	char buf[MAX_LINE_LEN];
	while(fgets(buf, sizeof(buf), todo))
	{
		if(head_initialized)
		{
			struct list_head *element = calloc(sizeof(struct list_head), 1);
			element->data = calloc(sizeof(buf), 1);
			strcpy_no_newline(element->data, buf);
			list_add_tail(element, head_ptr);
		}
		else
		{
			head_ptr->data = calloc(sizeof(buf), 1);
			strcpy_no_newline(head_ptr->data, buf);
			list_init(head_ptr);
			head_initialized++;
		}
	}
}

int main(void)
{
	struct list_head list;
	populate_list(&list);
	print_list(&list);

	printf("\n> ");

	char buf[MAX_LINE_LEN];
	char last_command[MAX_LINE_LEN];

	while(fgets(buf, sizeof(buf), stdin))
	{
		strcpy(last_command, buf);

		char *arg = get_arg_from_command(buf, 0);
		printf("'%s'\n", arg);
		if(strcmp(arg, "help") == 0)
		{
			printf("help, new, delete, move, undo\n");
		}
		else if(strcmp(arg, "new") == 0)
		{
			char *data = calloc(sizeof(buf), 1);
			strcpy_no_newline(data, get_pointer_to_arg(buf, 1));
			struct list_head *element = calloc(sizeof(struct list_head));
			element->data = data;
			list_add_tail(element, &list);
			print_list(&list);
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
