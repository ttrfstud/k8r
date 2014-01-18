#include <stdio.h>

main()
{
	int i, c, state, count;

	int nlength[20];

	for (i = 0; i < 20; i++)
		nlength[i] = 0;

	count = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (count > 20)
				continue;
			nlength[count - 1]++;
			count = 0;
		} else {
			count++;
		}
	}

	printf("Histogram:\n");

	for (i = 0; i < 20; i++) {
		printf("%d: [%d] ", (i + 1), nlength[i]);

		while(nlength[i]--)
			printf("#");

		printf("\n");
	}

}