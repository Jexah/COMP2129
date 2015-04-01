#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int width;
	int height;
	printf("Enter the size of the box: ");
	scanf("%2d %2d", &width, &height);
	printf("%dx %dy", width, height);
	return 0;
}
