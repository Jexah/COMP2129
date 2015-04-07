#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printPrimeFactorsAsString(int input)
{
	int first = 1;
	for(int i = 2; i <= input; ++i)
	{
		if(input % i == 0)
		{
			int notPrime = 0;
			for(int j = 2; j <= i; ++j)
			{
				if(i % j == 0 && i != j)
				{
					notPrime = 1;
					break;
				}
			}
			if(!notPrime)
			{
				input /= i;
				printf((first?"%d":" %d"), i);
				i = 1;
				first = 0;
			}
		}
	}
}

int main(void)
{
	char *buffer = calloc(sizeof(char), 11);
	if(fgets(buffer, sizeof(char)*11, stdin))
	{
		for(int i = 0; i < 11; ++i)
		{
			if(*(buffer+i) != 0 && *(buffer+i) != '\n' && *(buffer+i) != '-' && !isdigit(*(buffer+i)))
			{
				printf("Invalid input\n");
				return 1;
			}
		}

		int number = atoi(buffer);
		if(number <= 1)
		{
			printf("%d has no prime factors", number);
			return 1;
		}
		printPrimeFactorsAsString(number);
		return 0;
	}
	printf("Invalid input\n");
	return 1;
}
