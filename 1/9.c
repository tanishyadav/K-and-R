/* Exercise 1-9 */

#include <stdio.h>

/* copy input to output replacing consecutive blanks by a single blank */
int main(void)
{
	int c;
	int lc; /* last character */

	lc = 'a'; /* any random non-blank character */

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			if (lc != ' ')
				putchar(' ');
		if (c != ' ')
			putchar(c);
		lc = c;
	}

	return 0;
}
