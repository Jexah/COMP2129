#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int width;
	int height;
	printf("Enter the size of the box: ");
	if(scanf("%2d%2d", &width, &height) == 2 && width > 0 && width < 21 && height > 0 && height < 21)
	{
		for(int y = 0; y < height; ++y)
		{
			for(int x = 0; x < width; ++x)
			{
				if(y == 0 || y == height-1)
				{
					if(x == 0 || x == width-1)
					{
						printf("+");
						if(y != height-1 && x == width-1)
						{
							printf("\n");
						}
					}
					else
					{
						printf("-");
					}
				}
				else
				{
					if(x == 0 || x == width-1)
					{
						printf("|");
						if(x == width-1)
						{
							printf("\n");
						}
					}
					else
					{
						printf(" ");
					}
				}
			}
		}
	}
	else
	{
		printf("Invalid input");
	}
	return 0;
}
