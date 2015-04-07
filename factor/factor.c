#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *getPrimeFactorsAsString(int input)
{
	char *buffer = malloc(sizeof(char) * 50);
	char *cursor = buffer;
	int numberOfFactors = 0;
	printf("getPrimeFactorsAsString(%d)", input);
	for(int i = 2; i <= input / 2; ++i)
	{
		if(input % i == 0)
		{
			int notPrime = 0;
			for(int j = 2; j <= i / 2; j+=2)
			{
				if(i % j == 0)
				{
					notPrime = 1;
					break;
				}
				if(j == 2) --j;
			}
			if(!notPrime)
			{
				sprintf(cursor, "%d", i);
				cursor += strlen(cursor)+1;
				++numberOfFactors;
				printf("%d", i);
			}
		}
	}
}

int main(void)
{
	char *buffer = malloc(sizeof(char) * 11);
	if(fgets(buffer, sizeof(char)*11, stdin))
	{
		for(int i = 0; i < 11; ++i)
		{
			if(*(buffer+i) != 0 && !isdigit(*(buffer+i)))
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
		getPrimeFactorsAsString(2);
		return 0;
	}
	printf("Invalid input\n");
	return 1;
}
