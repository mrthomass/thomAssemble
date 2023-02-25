#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("COMMAND LINE ARGUMENT ERROR\n");
		return(1);
	}

	FILE *inp = fopen(argv[1], "r");
	if (inp == NULL)
	{
		printf("INPUT FILE ERROR\n");
		return(2);
	}

	FILE *opt = fopen(argv[2], "w");
	if (opt == NULL)
	{
		printf("OUTPUT FILE ERROR\n");
		return(3);
	}
// --------------------------------------------------------------------------------------
	char *read = malloc(sizeof(char) * 10);
	long s;
	long e;

	while (!feof(inp))
	{
		fscanf(inp, ">%*[^\n]\n");
		s = ftell(inp);
		fscanf(inp, "%*[^\n]");
		e = ftell(inp);
		fseek(inp, s, SEEK_SET);
		read = realloc(read, e-s + 1);
		fscanf(inp, "%s\n", read);

		printf("%s\n", read); // remove this guy later
	}

// --------------------------------------------------------------------------------------
	fclose(inp);
	fclose(opt);
}