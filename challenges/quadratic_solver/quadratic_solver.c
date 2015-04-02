#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quadratic
{
	float a;
	float b;
	float c;
} Quadratic;

int initializeQuadratic(Quadratic *quad)
{
	quad->a = 0;
	quad->b = 0;
	quad->c = 0;
}

int verifyQuadratic(Quadratic *quad)
{
	// check if quadratic is valid
}

int main(void)
{
	char buffer[25];
	if(fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		Quadratic quad;
		initializeQuadratic(&quad);
		quad.a = atof(buffer);
		char *firstSpace = strchr(buffer, ' ');
		quad.b = atof(firstSpace);
		char *secondSpace = strchr(firstSpace+1, ' ');
		quad.c = atof(secondSpace);
	}
	else
	{
		printf("Invalid input");
		return 1;
	}
	return 0;
}
