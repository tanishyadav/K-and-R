/* Exercise 1-21 */

/*
 * entab: replace blanks by minimum number of tabs and blanks; preferring tabs
 * over spaces.
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
 * tab2blank: give the number of blanks to replace a tab at index itab in a
 * line.
 */
int tab2blank(int itab, int tabstop);
/*
 * blank2tab: give the number of tabs (out[0]) and blanks (out[1]) to replace
 * nbalnk blanks starting from index iblank in a line.
 * NOTE: Assumes out[0] and out[1] initialized to 0.
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
				out[0] = out[1] = 0;
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

int tab2blank(int i, int ts)
{
	return ts - (i % ts);
}

void blank2tab(int i, int n, int ts, int out[])
{
	int t;
	t = tab2blank(i ,ts);
	if (t > n) {
		out[1] = out[1] + n;
	} else {
		out[0] = out[0] + 1;
		blank2tab(i + t, n - t, ts, out);
	}
}
