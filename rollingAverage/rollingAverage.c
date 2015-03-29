#include <stdio.h>

#define TOTAL_NUMBERS 4

int main(void)
{
	// Each number will be stored in this buffer, read one at a time.
	char buf[2];

	// This contains the last 4 numbers entered.
	char values[TOTAL_NUMBERS];

	// This stores the current index of the number being read.
	char current = 0;

	// This stores the total of all the last 4 numbers added up.
	char total = 0;

	// This loops through the input.
	while(NULL != fgets(buf, sizeof(buf), stdin))
	{
		if(*(buf) == 10){continue;}
		if(*(buf) == '\0')
		{
			break;
		}
		// If the current index is less than the total number of numbers allowed.
		if(current < TOTAL_NUMBERS)
		{
			// Calculate the value of the number inputted.
			*(values+current) = *(buf) - '0';

			// Add it to the total.
			total += *(values+current);
		}
		else
		{
			// Remove the old value stored in the index.
			total -= *(values+(current%TOTAL_NUMBERS));

			// Overwrite the old value.
			*(values+(current%TOTAL_NUMBERS)) = *(buf) - '0';

			// Add the new value to the total.
			total += *(values+(current%TOTAL_NUMBERS));
		}

		// Increment the current index.
		current++;
	}

	// If the current number of numbers is less than the total numbers allowed/required.
	if(current < TOTAL_NUMBERS)
	{
		printf("invalid input\n");
	}
	else
	{
		// Print the average of the TOTAL_NUMBERS.
		printf("%lf\n", total / (double)TOTAL_NUMBERS);
	}

	printf("%d %d\n", current, total);

	return 0;
}
