#include <stdio.h>

__asm__(".intel_syntax noprefix");


int main(void)
{
	char hello[] = "Hello";
	__asm__("mov %%eax, 64"
			"push %%eax;"
			"mov %%eax, 0"
			"push %%eax;"
			"call printf;"
			:
			:
			:"%eax"
	);
	return 0;
}
