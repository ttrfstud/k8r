#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else if (c == '\n') {
			putchar('\\');
			putchar('n');
		} else {
			putchar(c);
		}
		putchar('\n');
	}
}