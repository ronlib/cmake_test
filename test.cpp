// A simple program that computes the square root of a number
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <Config.h>
int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s version: %d.%d", argv[0], test_VERSION_MAJOR, 
			test_VERSION_MINOR);			
		fprintf(stdout, "Usage: %s number\n",argv[0]);
		return 1;
	}
	
	double inputValue = atof(argv[1]);
	double outputValue = sqrt(inputValue);
	fprintf(stdout,"The square root of %g is %g\n",
		  inputValue, outputValue);
	return 0;
}
