#include <stdio.h>
#include <string.h>

int arraysAreEqual(char *, char *, int);
void printFormatted(char *);
void go(char *, int);

void go(char *numberArray, int level)
{
	if(*(numberArray+level) != 26)
	{
		*(numberArray+level) += 1;
	}
	else
	{
		*(numberArray+level) = 1;
		go(numberArray, level - 1);
	}
}

int arraysAreEqual(char *array1, char *array2, int length)
{
	for(int i = 0; i < length; ++i)
	{
		if(*(array1+i) != *(array2+i))
		{
			return 0;
		}
	}
	return 1;
}


void printFormatted(char *numberArray)
{
	char output[10];

	for(int i = 0; i < 10; ++i)
	{
		output[i] = 0;
	}

	int current = 0;
	for(int i = 0; i < 10; ++i)
	{
		if(numberArray[i] != 0)
		{
			output[current] = numberArray[i] + '`';
			current++;
		}
	}
	printf("%s\n", output);
}

int main(int argc, char **argv)
{
	char number1[10];
	char number2[10];

	for(int i = 0; i < 10; ++i)
	{
		number1[i] = 0;
		number2[i] = 0;
	}

	for(int i = 0; i < 10; ++i)
	{
		int str1Len = strlen(*(argv+1));
		int str2Len = strlen(*(argv+2));
		if(i < str1Len)
		{
			number1[9-i] = *(*(argv+1)+(str1Len - 1 - i)) - '`';
		}
		if(i < str2Len)
		{
			number2[9-i] = *(*(argv+2)+(str2Len - 1 - i)) - '`';
		}
	}

	while(!arraysAreEqual(number1, number2, 10))
	{
		go(number1, 9);
		printFormatted(number1);
	}
	return 0;
}

