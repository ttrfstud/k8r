#include <stdio.h>

int detabtab(char s[], int len, int pos, int nexttab);

void detab(char s[], int len, int n);

int min(int a, int b);

void prettyprint(char s[], int len);

void should(char is[], char should[]);

main()
{
	char s1[100] = "johnny\tate\tlunch\n";
	char s2[100] = "johnny\tate\tlunch\n";
	char s3[100] = "johnny\tate\tlunch\n";
	char s4[100] = "johnny\tate\tlunch\n";
	char s5[100] = "johnny\tate\tlunch\n";

	detab(s1, 100, 4);
	should(s1, "johnny__ate_lunch\n");

	detab(s2, 100, 5);
	should(s2, "johnny____ate__lunch\n");

	detab(s3, 100, 6);
	should(s3, "johnny______ate___lunch\n");

	detab(s4, 100, 7);
	should(s4, "johnny_ate____lunch\n");

	detab(s5, 100, 8);
	should(s5, "johnny__ate_____lunch\n");

	return 0;
}

void should(char is[], char should[])
{
	int len1;
	int len2;

	int i;

	len1 = 0;
	len2 = 0;

	for (i = 0; is[i] != '\0'; i++) {
		len1++;
		printf("exp[%d] = %c\n", i, is[i]);		
	}

	for (i = 0; should[i] != '\0'; i++) {
		len2++;
		printf("act[%d] = %c\n", i, should[i]);		
	}

	if (len1 != len2) {
		printf("\nActual string is not equal to expected string...\n");
		printf("(Actual: %d, expected %d)\n\n", len1, len2);		
	} else {
		printf("\nOK, passed!\n");
	}

	prettyprint(is, len1);
	prettyprint(should, len2);
}

int min(int a, int b)
{
	return a > b ? b : a;
}

void prettyprint(char s[], int len)
{
	int i;

	int c;

	for (i = 0; i < len; i++) {
		if (s[i] == '\t') {
			putchar('\\');
			putchar('t');
		} else if (s[i] == ' ') {
			putchar('_');
		} else {
			putchar(s[i]);
			c = s[i];
		}
	}

	if (c != '\n') {
		putchar('\\');
		putchar('n');
		putchar('\n');
	}
}

void detab(char s[], int len, int n)
{
	int i;
	int nexttab;

	nexttab = n - 1;

	for (i = 0; i < len; i++) {
		if (s[i] == '\t') {
			printf("nexttab: %d\n", nexttab);
			i = detabtab(s, len, i, nexttab);
			nexttab = n;
		}

		nexttab = nexttab ? nexttab - 1 : n - 1;
	}
}

/* detab: remove tab at position pos and replace it with
	space and adds nexttab spaces after it */
int detabtab(char s[], int len, int pos, int nexttab)
{
	char temp[len];

	int i, j;

	j = 0;

	for (i = pos + 1; i < len; i++) {
		temp[j++] = s[i];
	}

	temp[j] = '\0';

	for (i = pos; i < min(len, pos + nexttab + 1); i++)
		s[i] = ' ';

	j = 0;
	for (; i < len; i++) {
		s[i] = temp[j++];
	}

	return min(len, pos + nexttab);
}