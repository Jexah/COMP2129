#include <stdio.h>
unsigned factorial(unsigned n) {
	int result = 1;
	if (n > 1) {
		result = n * factorial(n - 1);
	}
	return result;
}
int main(void) {
	printf("%d\n", factorial(3));
}

