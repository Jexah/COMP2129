#include <stdio.h>
#include <string.h>

int printFile(char *filename, char *buffer)
{
	FILE *currentFile = fopen(filename, "r");
	if(!currentFile)
	{
		char buf[100];
		sprintf(buf, "File %s does not exist", filename);
		perror(buf);
		return 1;
	}
	while(NULL != fgets(buffer, sizeof(buffer), currentFile))
	{
		printf("%s", buffer);
	}
	return 0;
}


int main(int argc, char **argv)
{
	int done = 0;
	char contents[10000];
	for(int i = 1; i < argc; ++i)
	{
		if(printFile(*(argv+i), contents))
		{
			return 1;
		}
		done = 1;
	}
	if(done)
	{
		return 0;
	}

	char buffer[100];
	while(NULL != fgets(buffer, sizeof(buffer), stdin))
	{
		if(printFile(buffer, contents))
		{
			return 1;
		}
	}
	return 0;
}
