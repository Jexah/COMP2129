#include <stdio.h>

int main(void)
{
	char buf[100];
	char output[100];
	char current = 0;
	while(NULL != fgets(buf, sizeof(buf), stdin))
	{
		char len = 0;
		while(*(buf+len) != '\0')
		{
			len++;
		}
		for(int i = 0; i < len-1; ++i)
		{
			*(output+len-i-1) = *(buf+i);
		}
		*(output+len) = '\0';
		current++;
		printf("%s\n", output);
	}
	return 0;
}
