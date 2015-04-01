#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Size
{
	int width;
	int height;
} Size;


Size *populateSize(char *input, Size *size)
{
	if(strlen(input) < 3 || strlen(input) > 5)
	{
		perror("Invalid input");
		exit(0);
	}
	size->width = atoi(&input[0]);
	size->height = atoi(&input[2]);
	return size;
}

int isSizeAcceptable(Size *size)
{
	if(size->width < 1 || size->width > 20)
	{
		return 0;
	}
	if(size->height < 1 || size->height > 20)
	{
		return 0;
	}
	return 1;
}

int main(void)
{
	char buf[5];
	printf("Enter the size of the box: ");

	if(fgets(buf, sizeof(buf), stdin))
	{
		Size size;
		populateSize(buf, &size);
		if(!isSizeAcceptable(&size))
		{
			perror("Invalid input");
			exit(0);
		}
		for(int y = 0; y < size.height; ++y)
		{
			for(int x = 0; x < size.width; ++x)
			{
				if(y == 0 || y == size.height-1)
				{
					if(x == 0 || x == size.width-1)
					{
						printf("+");
						if(y != size.height-1 && x == size.width-1)
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
					if(x == 0 || x == size.width-1)
					{
						printf("|");
						if(x == size.width-1)
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
	return 0;
}
