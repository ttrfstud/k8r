#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF)
		if (c != '\n')
			printf("c is %c and %d\n", c, c != EOF);
}