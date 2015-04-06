#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum
{
	SUCCESS, FAIL
} Status;

typedef enum
{
	VALID, A, B, C
} Validity;

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

Validity verifyQuadratic(Quadratic *quad)
{
	if(quad->a == 0)
	{
		return A;
	}
	else if(quad->b == 0)
	{
		return B;
	}
	else if(quad->c == 0)
	{
		return C;
	}
	return VALID;
}

Status solveRoots(Quadratic *quad, Roots *roots)
{
	if(pow(quad->b, 2) - 4*quad->a*quad->c < 0)
	{
		return FAIL;
	}
	roots->x1 = ((-quad->b) - sqrt(pow(quad->b, 2)-(4*quad->a*quad->c))) / (2*quad->a);
	roots->x2 = ((-quad->b) + sqrt(pow(quad->b, 2)-(4*quad->a*quad->c))) / (2*quad->a);
	return SUCCESS;
}

Status getFloat(char *string, float *container)
{
	char errorBuffer = 0;
	char *errorBufferPtr = &errorBuffer;
	float tmp = (float)(strtod(string, &errorBufferPtr));
	if(*errorBufferPtr == ' ' || *errorBufferPtr == '\n' || *errorBufferPtr == 0)
	{
		*container = tmp;
		return SUCCESS;
	}
	return(FAIL);
}

Status getFloats(char *string, Quadratic *quad)
{
	if(getFloat(string, &(quad->a)) == FAIL)
	{
		return FAIL;
	}
	char *firstSpace = strchr(string, ' ');
	if(firstSpace == NULL)
	{
		return FAIL;
	}
	if(getFloat(firstSpace+1, &(quad->b)) == FAIL)
	{
		return FAIL;
	}
	char *secondSpace = strchr(firstSpace+1, ' ');
	if(secondSpace == NULL)
	{
		return FAIL;
	}
	if(getFloat(secondSpace+1, &(quad->c)) == FAIL)
	{
		return FAIL;
	}
	return SUCCESS;
}


int main(void)
{
	char buffer[25];
	if(fgets(buffer, sizeof(buffer), stdin))
	{
		Quadratic quad = {0};
		Roots roots = {0};

		if(getFloats(buffer, &quad) == FAIL)
		{
			printf("Invalid input");
			return FAIL;
		};

		Validity quadraticValidity = verifyQuadratic(&quad);
		switch(quadraticValidity)
		{
			case A:
				printf("'a'");
				break;
			case B:
				printf("'b'");
				break;
			case C:
				printf("'c'");
				break;
			case VALID:
				break;
		}
		if(quadraticValidity != VALID)
		{
			printf(" must be non-zero");
			return FAIL;
		}

		if(solveRoots(&quad, &roots) == FAIL)
		{
			printf("No roots\n");
			return(FAIL);
		}

		if(roots.x1 != roots.x2)
		{
			printf("X1 = %.1f\n", roots.x1);
			printf("X2 = %.1f", roots.x2);
		}
		else
		{
			printf("X = %.1f\n", roots.x1);
		}
		return SUCCESS;
	}
	printf("Invalid input\n", buffer);
	return FAIL;
}
