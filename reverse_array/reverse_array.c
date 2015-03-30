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
	if(*target->length == *target->capacity)
	{
		array_t *newArray = realloc(*target, sizeof(int) * capacity * 2);
		if(newArray == NULL) return 0;
		*target = newArray;
		*target->capacity *= 2;
	}
	*target->head[length] = x;
	return 1;
}

int main(void)
{
	array_t *myArray = createArray();
	if(appendNumber(5, &myArray))
	{
		printf("Success!");
		printf("%d", myArray->head[0]);
	}
	return 0;
}
