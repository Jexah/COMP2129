#include <stdio.h>

int main(void)
{
	char buf[128];
	while(NULL != fgets(buf, sizeof(buf), stdin))
	{
		char output[128];
		for(char i = 0; i < sizeof(buf); ++i)
		{
			if(*(buf+i) >= 96 && *(buf+i) <= 122)
			{
				*(output+i) = *(buf+i)-48;
			}
			else
			{
				*(output+i) = *(buf+i);
			}
		}
		printf("%s", output);
	}
}
