/* Exercise 1-21 */

/*
 * entab: replace blanks by minimum number of tabs and blanks; preferring tabs
 * over spaces except when there is only one blank.
 */

#include <stdio.h>

#define IN      1
#define OUT     0
#define TABSTOP 8

/*
 * putcn: putchar(c), n times.
 */
void putcn(char c, int n);
/*
 * blank2tab: give the number of tabs (out[0]) and blanks (out[1]) to replace
 * nbalnk blanks starting from index iblank in a line.
 */
void blank2tab(int iblank, int nblank, int tabstop, int out[]);

int main(void)
{
	int c;
	int i;
	int j;          /* number of blanks encountered so far */
	int out[2];     /* to store blank2tab output */
	int state;

	i = j = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			state = IN;
			++j;
		} else {
			if (state == IN) {
				blank2tab(i, j, TABSTOP, out);
				putcn('\t', out[0]);
				putcn(' ', out[1]);
				i = i + j;
				j = 0;
				state = OUT;
			}
			++i;
			if (c == '\n')
				i = 0;
			putchar(c);
		}
	}

	return 0;
}

void putcn(char c, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		putchar(c);
}

void blank2tab(int i, int n, int ts, int out[])
{
	int t;  /* spaces to align to next tab boundary */

	/* if only one space then do nothing */
	if (n == 1) {
		out[0] = 0;
		out[1] = 1;
		return;
	}

	t = ts - (i % ts);
	if (t > n) {
		out[0] = 0;
		out[1] = n;
	} else {
		out[0] = 1 + (n - t) / ts;
		out[1] = (n - t) % ts;
	}
}
