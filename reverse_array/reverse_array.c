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
	newArray.head = calloc(sizeof(int) * capacity);
	if(newArray.head == NULL) die();
	return &newArray;
}

int main(void)
{
	array_t *myArray = createArray();
}
