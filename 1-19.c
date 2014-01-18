#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int len);
void reverse(char s[]);


main()
{
	char line[MAXLINE];

	int len;

	while ((len = getline(line, MAXLINE)) != EOF) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

int getline(char s[], int len)
{
	int i;

	int c;

	for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n')
		s[i] = c;

	s[i + 1] = '\0';

	return i;
}


void reverse(char s[])
{
	int len, i;

	char buffer;

	len = 0;

	while(s[len++] != '\0')
		;

	if (len - 3 < 0) {
		printf("returning?\n");
		return;	
	} else {
		len = len - 2;
		for (i = 0; i <= len / 2; i++) {
			printf("exchanging: %c and %c\n", s[i], s[len - i - 1]);
			buffer = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = buffer;
		}
	}
}