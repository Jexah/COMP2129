#include <stdio.h>

int main(void)
{
	int loominarty;
	printf("Enter a number: ");
    scanf("%d", &loominarty);
	printf("%d %s", loominarty, (loominarty%2==1)?("is odd"):("is even"));
	return 0;
}
