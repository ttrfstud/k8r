#include <stdio.h>

#define ASCII_RANGE 256

#define p printf

main()
{
	int i, c;
	int nchars[ASCII_RANGE];

	for (i = 0; i < ASCII_RANGE; i++)
		nchars[i] = 0;

	while ((c = getchar()) != EOF)
		nchars[c]++;

	for (i = 0; i < ASCII_RANGE; i++) {
		p("%c : %d", i, nchars[i]);
		while (nchars[i]--)
			putchar('#');	

		putchar('\n');
	}
}