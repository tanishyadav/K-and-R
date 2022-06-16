/* Exercise 1-20 */
/* detab: replace tabs in input with blanks */

#include <stdio.h>

#define TABSTOP  8
#define BLANK   ' '

/*
 * tab2blank: give the number of blanks to replace a tab at index itab in a
 * line.
 */
int tab2blank(int itab, int tabstop);
/*
 * putcn: putchar(c), n times.
 */
void putcn(char c, int n);


int main(void)
{
	int c, i, b;

	for (i = 0; (c = getchar()) != EOF; ++i) {
		if (c == '\t') {
			b = tab2blank(i, TABSTOP);
			putcn(BLANK, b);
			i = i + (b - 1);
		} else {
			putchar(c);
		}
		if (c == '\n')
			i = -1;
	}

	return 0;
}

int tab2blank(int i, int ts)
{
	return ts - (i % ts);
}

void putcn(char c, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		putchar(c);
}
