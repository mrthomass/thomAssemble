#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nToCheck(char *R1, char *R2, int thresh);
int maxDiag(char *R1, char *R2);

int main(void)
{
	char *apple = "AGAG";
	char *grep = "ATCCA";

	printf("%i\n", maxDiag(apple, grep));

	printf("ncheck: %i\n", nToCheck(apple, grep, 4));
}

int nToCheck(char *R1, char *R2, int thresh)
{
	return(strlen(R1) + strlen(R2) + 1 - 2 * thresh);
}

int maxDiag(char *R1, char *R2)
{
	if (strlen(R1) > strlen(R2))
	{
		return(strlen(R1) - strlen(R2) + 1);
	}
	else
	{
		return(strlen(R2) - strlen(R1) + 1);
	}
}