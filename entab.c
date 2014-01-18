#include <stdio.h>

int entabspace(char s[], int len, int pos, int tabstop, int nexttab, int scount);

void entab(char s[], int len, int tabstop);

void should(char is[], char should[]);

int scount(char s[], int i, int len); 

main()
{
	char s1[100] = "johnny______ate____lunch\n";
	char s2[100] = "johnny______ate____lunch\n";
	char s3[100] = "johnny______ate____lunch\n";
	char s4[100] = "johnny______ate____lunch\n";
	char s5[100] = "johnny______ate____lunch\n";
	char s6[100] = "johnny______ate____lunch\n";
	char s7[100] = "johnny______ate____lunch\n";

	entab(s1, 100, 4);
	should(s1, "johnnyTTate____lunch\n");
	entab(s2, 100, 5);
	should(s2, "johnnyT__ate____lunch\n");
	entab(s3, 100, 6);
	should(s3, "johnnyTateT_lunch\n");
	entab(s4, 100, 7);
	should(s4, "johnny______ate____lunch\n");
	entab(s5, 100, 8);
	should(s5, "johnnyT____ate____lunch\n");
	entab(s6, 100, 9);
	should(s6, "johnnyT___ateT_lunch\n");
	entab(s7, 100, 10);
	should(s7, "johnnyT__ate____lunch\n");

	return 0;
}

void should(char is[], char should[])
{
	int len1, len2;
	int i;

	int passed;

	len1 = len2 = 0;

	passed = 1;

	for (len1 = 0; is[len1] != '\0'; len1++);
	for (len2 = 0; should[len2] != '\0'; len2++);

	if (len1 != len2) {
		printf("Actual (%d) len != expected (%d) len !\n", len1, len2);
		passed = 0;
	}

	if (passed) {
		for (i = 0; i < len1; i++)
			if (is[i] != should[i])
				passed = 0;
	}

	if (!passed) {
		printf("%s", is);
		printf("%s", should);
	} else {
		printf("Passed, OK!\n");
	}
}

void entab(char s[], int len, int tabstop)
{
	int i;
	int nexttab;
	int sc;

	nexttab = tabstop - 1;

	for (i = 0; i < len && s[i] != '\0'; i++) { /* != '\0' because it's going to shrink*/
		
		// printf("position: %d, nexttab: %d, char: %c\n", i, nexttab, s[i]);
		if (s[i] == '_') {
			sc = scount(s, i, len);
			i = entabspace(s, len, i, tabstop, nexttab, sc);
			i--;
			if (sc >= nexttab + 1) {
				sc = sc - nexttab - 1;
				nexttab = (sc % tabstop);

				if (nexttab)
					nexttab = tabstop - nexttab;
			} else {
				nexttab = nexttab - sc + 1;
			}
		}

		nexttab = nexttab ? nexttab - 1 : tabstop - 1;	
	}
}

int entabspace(char s[], int len, int pos, int tabstop, int nexttab, int scount)
{

	// printf("\ncheckin2.. %s %d %d %d %d %d\n", s, len, pos, tabstop, nexttab, scount);

	char temp[len];

	int i, j, nextpos;

	if (nexttab == 0 && scount == 1) {
		return pos + 1;
	}

	for (i = pos + scount, j = 0; i < len; i++, j++) {
		temp[j] = s[i];
	}

	i = 0;

	// printf("temp: %s", temp);

	while(scount) {
		if (scount >= nexttab + 1) {
			s[pos + i++] = nexttab ? 'T' : '_';
			scount = scount - nexttab - 1;
			nexttab = tabstop - 1;
		} else if (scount < nexttab + 1) {
			do {
				s[pos + i++] = '_';
			} while(--scount);
		}
	}

	nextpos = pos + i;

	for (i = nextpos, j = 0; temp[j] != '\0'; i++, j++) {
		s[i] = temp[j];
	}

	s[i] = temp[j];

	// printf("after: %s", s);

	return nextpos;
}

int scount(char s[], int i, int len)
{
	int count;

	count = 0;

	while(i < len && s[i++] == '_')
		count++;

	return count;
}