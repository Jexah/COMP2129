#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum
{
	SUCCESS, FAIL
} Status;

typedef struct Quadratic
{
	float a;
	float b;
	float c;
} Quadratic;

typedef struct Roots
{
	float x1;
	float x2;
} Roots;

Status initializeQuadratic(Quadratic *quad)
{
	quad->a = 0;
	quad->b = 0;
	quad->c = 0;
	return SUCCESS;
}

Status initializeRoots(Roots *roots)
{
	roots->x1 = 0;
	roots->x2 = 0;
	return SUCCESS;
}

Status verifyQuadratic(Quadratic *quad)
{
	if(quad->a == 0)
	{
		printf("'a' must be non-zero");
		return FAIL;
	}
	else if(quad->b == 0)
	{
		printf("'b' must be non-zero");
		return FAIL;
	}
	else if(quad->c == 0)
	{
		printf("'c' must be non-zero");
		return FAIL;
	}
	return SUCCESS;
}

Status solveRoots(Quadratic *quad, Roots *roots)
{
	if(quad->b*quad->b - 4*quad->a*quad->c < 0)
	{
		return FAIL;
	}
	roots->x1 = ((-quad->b) - sqrt((quad->b*quad->b)-(4*quad->a*quad->c))) / (2*quad->a);
	roots->x2 = ((-quad->b) + sqrt((quad->b*quad->b)-(4*quad->a*quad->c))) / (2*quad->a);
	return SUCCESS;
}

float getFloat(char *string)
{
	char *errorBuffer;
	*errorBuffer = 0;
	float tmp = (float)(strtod(string, &errorBuffer));
	printf("'%c'", *errorBuffer);
	if(*errorBuffer == ' ' || *errorBuffer == '\n' || *errorBuffer == '\0')
	{
		return tmp;
	}
	printf("Invalid input1");
	exit(FAIL);
}

Status getFloats(char *string, Quadratic *quad)
{
	quad->a = getFloat(string);
	char *firstSpace = strchr(string, ' ');
	quad->b = getFloat(firstSpace);
	char *secondSpace = strchr(firstSpace+1, ' ');
	quad->c = getFloat(secondSpace);
	return SUCCESS;
}


int main(void)
{
	char buffer[25];
	if(fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		Quadratic quad;
		initializeQuadratic(&quad);

		Roots roots;
		initializeRoots(&roots);
		getFloats(buffer, &quad);

		if(verifyQuadratic(&quad) == SUCCESS)
		{
			if(solveRoots(&quad, &roots) == SUCCESS)
			{
				printf("X1: %.1f\n", roots.x1);
				if(roots.x1 != roots.x2)
				{
					printf("X2: %.1f", roots.x2);
				}
			}
			else
			{
				printf("No roots");
				exit(1);
			}
		}
		else
		{
			return(FAIL);
		}
	}
	else
	{
		printf("'%s'Invalid input2", buffer);
		return FAIL;
	}
	return SUCCESS;
}
