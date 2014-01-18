#include <stdio.h>

main()
{
	int c, prev;

	while ((c = getchar()) != EOF) {
		if (prev == ' ' && c == ' ') {
			prev = c;
			continue;
		}		

		putchar(c);
		prev = c;
	}
}