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
	if(target->length > 100){return 0;}
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

	char buf[10] = {0};

	while(NULL != fgets(buf, sizeof(buf), stdin))
	{
		appendNumber(atoi(buf), myArray);
	}

	for(int i = myArray->length; i >= 0; --i)
	{
		printf("%d\n", myArray->head[i]);
	}

	return 0;
}
