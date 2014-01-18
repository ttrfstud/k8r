#include <stdio.h>

#define W while
#define I int

/* count lines in input */
main()
{
	I c, nl;

	nl = 0;

	W ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}