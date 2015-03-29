#include <stdio.h>
#define TOTAL 4




int main(void) {

	struct digimon
	{
		char name[10];
		unsigned level;
	};
	struct digimon digimons[TOTAL];
	for (unsigned i = 0; i < TOTAL; i++) {
		if (scanf("%9s %u", digimons[i].name, &digimons[i].level) != 2) {
			fprintf(stderr, "error\n");
			return 1;
		}
	}
	printf("sizeof(char [10]) = %zu\n", sizeof(char[10]));
	printf("sizeof(unsigned) = %zu\n", sizeof(unsigned));
	printf("sizeof(struct digimon) = %zu\n", sizeof(struct digimon));
	printf("sizeof(digimons) = %zu\n", sizeof(digimons));
	// save to file
	FILE *file = fopen("digimon.save", "w");
	fwrite(digimons, sizeof(struct digimon), TOTAL, file);
	fclose(file);
	return 0;
}
