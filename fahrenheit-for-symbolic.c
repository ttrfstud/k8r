#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
#define FAHR fahr
#define FOR for
main()
{
	int fahr;

	for (fahr = LOWER; FAHR <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));

	FOR (fahr = LOWER; FAHR <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}