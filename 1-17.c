#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int len);

main()
{
	char line[MAXLINE];

	int len;

	while((len = getline(line, MAXLINE)) > 0)
		if (len > 80)
			printf("%s %d\n", line, len);
}

int getline(char s[], int len)
{
	int c, i;

	for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	
	if (c == '\n')
		s[i] = c;

	s[i + 1] = '\0';

	return i;
}