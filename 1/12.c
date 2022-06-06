/* Exercise 1-12 */

#include <stdio.h>

#define IN  1
#define OUT 0

/* print input one word per line */
int main(void)
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t' || c == '\n')) {
			if (state == IN) {
				state = OUT;
				putchar('\n');
			}
		} else {
			state = IN;
			putchar(c);
		}
	}

	return 0;
}
