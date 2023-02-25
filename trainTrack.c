#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *ra = "ACAGTGCCAGTAGGAGCAGGAC";
	char *rb = "GCCAG";
	int raLen = strlen(ra);
	int rbLen = strlen(rb);
	int minLink = 2;
	
	
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
	  
		if ((rbLen - minLink) > i)
		{
		  // check `check` amount of characters
		  for (int k = 0; k < check; k++)
		  {
		    if (rb[rbLen - minLink - i + k] != ra[k])
		    {
		      break;
		    }
		    if (k == check - 1)
		    {
		      printf("%i Was Worthy\n", i);
		    }
		  }
		  
		}
		else
		{
		  
		  for (int k = 0; k < check; k++)
		  {
		    if (rb[k] != ra[minLink - rbLen + i + k])
		    {
		      break;
		    }
		    if (k == check - 1)
		    {
		      printf("%i Was Worthy\n", i);
		    }
		  }
		}
		
	}
}