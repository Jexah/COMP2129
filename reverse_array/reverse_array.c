#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *head;
	int length, capacity;
} array_t;

void die(void)
{
	perror("Whoops!");
	exit(1);
}

array_t *createArray(void)
{
	array_t newArray;
	newArray.length = 0;
	newArray.capacity = 4;
	newArray.head = calloc(sizeof(int), newArray.capacity);
	if(newArray.head == NULL) die();
	return &newArray;
}

int appendNumber(int x, array_t **target)
{
	if(((array_t *)*target)->length == ((array_t *)*target)->capacity)
	{
		array_t *newArray = realloc((array_t *)*target, sizeof(int) * ((array_t *)*target)->capacity * 2);
		if(newArray == NULL) return 0;
		*target = newArray;
		((array_t *)*target)->capacity = ((array_t *)*target)->capacity * 2;
	}
	((array_t *)*target)->head[((array_t *)*target)->length++] = x;
	return 1;
}

int main(void)
{
	array_t *myArray = createArray();

	printf("%d\n", myArray->head[0]);
	printf("%p\n", myArray);

	if(appendNumber(5, &myArray))
	{
		printf("Success!");
		printf("%p\n", myArray);
		printf("%d\n", myArray->head[0]);
	}
	return 0;
}
