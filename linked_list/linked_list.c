#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	Node *next;
	int value;
};

int prependToList(Node **list, Node **node)
{
	(*node)->next = *list;
	*list = *node;
	return 1; // Success
}

Node *createNode(void)
{
	Node *temp = calloc(sizeof(Node), 1);
	temp->next = NULL;
	temp->value = 0;
	return temp;
}

int main(void)
{
	Node *list = createNode();

	Node *node = createNode();

	node->value = 5;

	prependToList(&list, &node);

	printf("%d\n", list->value);

	return 0;
}
