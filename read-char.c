#include <stdio.h>

/*copy input to output; 1st version */

main()
{
	int c;

	c = getchar();
	printf("c is %c\n", c);
	while (c != EOF) {
		putchar(c);
		c = getchar();
		printf("c is %c\n", c);
	}
}