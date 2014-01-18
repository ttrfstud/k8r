#include <stdio.h>

#define WAS_NL 1
#define WAS_NO_NL 0

main()
{
	int c, was_nl;

	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t' || c == '\n')) {
			if (was_nl != WAS_NL) {
				putchar('\n');
			}
			was_nl = WAS_NL;
		} else {
			was_nl = WAS_NO_NL;
			putchar(c);
		}
	}
}