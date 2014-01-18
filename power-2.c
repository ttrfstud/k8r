#include <stdio.h>

#define p printf

int power(int base, int n);

main()
{
	int i;

	for (i = 0; i < 11; i++)
		p("%d %d %d\n", i, power(2, i), power(-3, i));
}

int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}