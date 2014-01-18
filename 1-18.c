#include <stdio.h>

#define MAXLINE 1000

#define RET0 return 0;

int getline(char s[], int len);

main()
{
	char line[MAXLINE];

	int len;
	int i;

	while ((len = getline(line, MAXLINE)) > 0) {
		i = len;
		printf("%s|\n", line);
		while(--i)
			if (line[i] == '\t' || line[i] == ' ') {
				printf("line contains trailing space...\n");
				line[i]	= '\0';			
			}
		printf("%s|\n", line);
	}

	RET0
}

int getline(char s[], int len)
{
	int i;

	int c;

	for (i = 0; i < len - 1 && (c = getchar()) != EOF && c!='\n'; i++)
		s[i] = c;

	s[i] = '\0';

	return i;
}