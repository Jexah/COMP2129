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
	array_t *newArray = calloc(sizeof(array_t), 1);
	newArray->length = 0;
	newArray->capacity = 4;
	newArray->head = calloc(sizeof(int), newArray->capacity);
	if(newArray->head == NULL) die();
	return newArray;
}

int appendNumber(int x, array_t *target)
{
	if(target->length == target->capacity)
	{
		void *temp = realloc(target->head, sizeof(int) * target->capacity * 2);
		if(temp == NULL) return 0;
		target->head = temp;
	}
	target->head[target->length++] = x;
	return 1;
}

int main(void)
{
	array_t *myArray = createArray();

	printf("%d\n", myArray->head[0]);
	printf("%p\n", myArray->head);
	printf("%p\n", myArray);

	if(appendNumber(5, myArray))
	{
		printf("Success!\n");
		printf("%p\n", myArray);
		printf("%p\n", myArray->head);
		printf("%d\n", myArray->head[0]);
	}
	return 0;
}
