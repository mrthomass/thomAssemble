#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *ra = "ATGCCAGTAGGAGCAGGAC";
	char *rb = "GCAGGACCCA";
	int raLen = strlen(ra);
	int rbLen = strlen(rb);
	int minLink = 5;
	
	
	int nrep = rbLen - raLen + 1;
	long maxLink = raLen;
	if (rbLen < raLen)
	{
	  maxLink = rbLen;
	  nrep = raLen - rbLen + 1;
	}
	
	int repCount = 0;
  int check = minLink - 1;
	
	for (int i = 0; i < raLen + rbLen - 2 * minLink + 1; i++)
	{
	  // we have to set up how many units to check we have a minimum and a maximum
	  if (check < maxLink && repCount != nrep)
	  {
	    check++;
	  }
	  if (repCount == nrep)
	  {
	    check--;
	  }
	  if (check == maxLink)
	  {
	    repCount++;
	  }
	  
	  printf("check: %i\n", check);
	  
		if ((rbLen - minLink) > i)
		{
		  if (rb[rbLen - minLink - i] == ra[0])
		  {
		    if (rb[rbLen - minLink - i + 1] == ra[0 + 1])
		    {
		      printf("good: %i\n", i);
		    }
		  }
		}
		else
		{
		  if (rb[0] == ra[minLink - rbLen + i])
		  {
		    if (rb[0 + 1] == ra[minLink - rbLen + i + 1])
		    {
		      printf("Good: %i\n", i);
		    }
		  }
		}
	}
}