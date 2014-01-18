#include <stdio.h>

#define p printf

main()
{
	int c, nlength[20], i, state;

	int count, max;

	count = 0;

	for (i = 0; i < 20; i++)
		nlength[i] = 0;


	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			if (count > 20)
				continue;
			nlength[count - 1]++;
			count = 0;
		} else {
			count++;
		}

	p("Histogram:\n");

	max = -1;

	for (i = 0; i < 20; i++)
		if (nlength[i] > max)
			max = nlength[i];

	while (max) {
		for (i = 0; i < 20; i++)
			if (nlength[i] >= max) {
				p("#  ");
			} else {
				p("   ");
			}
		putchar('\n');
		max--;
	}

	for (i = 0; i < 20; i++)
		p("_  ");

	putchar('\n');

	for (i = 0; i < 20; i++)
		p("%1d  ", nlength[i]);
}