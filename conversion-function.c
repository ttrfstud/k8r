#include <stdio.h>

#define LOWER 0
#define UPPER 200
#define STEP 5

#define p printf

float convert(float celsius);

main() {

	int i;

	for (i = LOWER; i <= UPPER; i = i + STEP)
		p("%3d\t%6.1f\n", i, convert(i));


	return 0;
}

float convert(float celsius)
{
	return 9.0 / 5.0 * (celsius + 32);
}