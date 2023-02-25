#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this main, maps two reads onto each other and outputs the combined string
// in the case of two exact hits it will map to the one with the higher nnm (number of nucleotide matched)


int main(int argc, char *argv[])
{
	char *ra = "TACACTA";
	char *rb = "GTGTACAC";
	int raLen = strlen(ra);
	int rbLen = strlen(rb);
	int minLink = 4;
	
	
	int nrep = rbLen - raLen + 1;
	long maxLink = raLen;
	if (rbLen < raLen)
	{
	  maxLink = rbLen;
	  nrep = raLen - rbLen + 1;
	}
	
	int repCount = 0;
  int check = minLink - 1;
  int nnm = 0;
  int fin;
	
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
	  
	  
	  // test the time of check with or without this here
	  if (nnm > check - 1)
	  {
	    break;
	  }
	  // this is a optimization step ^^^ gets rid of redundancy
	  
		if ((rbLen - minLink) > i)
		{
		  // check `check` amount of characters
		  for (int k = 0; k < check; k++)
		  {
		    if (rb[rbLen - minLink - i + k] != ra[k])
		    {
		      break;
		    }
		    if (k == check - 1 && check > nnm)
		    {
		      nnm = check;
		      fin = i;
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
		    if (k == check - 1 && check > nnm)
		    {
		      nnm = check;
		      fin = i;
		    }
		  }
		}
		
	}
	
	printf("%i\n", fin);
	
}




