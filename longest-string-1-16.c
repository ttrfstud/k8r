#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int len);
void copy(char from[], char to[]);

main()
{
	char current[MAXLINE];
	char longest[MAXLINE];

	int max;
	int len;

	int i;

	max = 0;

	while ((len = getline(current, MAXLINE)) > 0) {
		if (len > max) {
			copy(current, longest);
			max = len;			
		}
	}
		

	printf("%s", longest);
	printf("%d\n", max);

	return 0;
}

int getline(char s[], int len)
{
	int c;
	int i;

	int reallen;

	reallen = 0;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < len - 1)
			s[i] = c;
		reallen++;
	}

	if (i < len - 1) {
		if (c == '\n')
			s[i] = c;
		s[i + 1] = '\0';
	}

	return reallen;
}

void copy(char from[], char to[])
{
	int i;

	i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}