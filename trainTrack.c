#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *ra = "ATCAGGAGTAGA";
	char *rb = "AGCCAGATCAGG";
	int minLink = 6;


	for (int i = 0; i < strlen(ra) + strlen(rb) - 2 * minLink + 1; i++)
	{
		if ((strlen(rb) - minLink) > i)
		{
		  if (rb[strlen(rb) - minLink - i] == ra[0])
		  {
		    if (rb[strlen(rb) - minLink - i + 1] == ra[0 + 1])
		    {
		      printf("good: %i\n", i);
		    }
		  }
		}
		else
		{
		  if (rb[0] == ra[minLink - strlen(rb) + i])
		  {
		    if (rb[0 + 1] == ra[minLink - strlen(rb) + i + 1])
		    {
		      printf("Good: %i\n", i);
		    }
		  }
		}
	}
}