#include <stdio.h>

int main(void)
{
	FILE *myfile = fopen("filename.txt", "w");

	if(!myfile)
	{
		perror("loololol");
		return 1;
	}
	fprintf(myfile, "yolooo");
	fclose(myfile);
}
