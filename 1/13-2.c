/* Exercise 1-13 */
/* VERTICAL */

#include <stdio.h>

#define IN  1
#define OUT 0
#define HIST_CHAR '*'
#define MAXLEN 10

/* print a histogram of length of words in input */
int main(void)
{
	int i, j, c, state, len, max;
	int lenarr[MAXLEN + 1];

	state = OUT;
	max = len = 0;
	for (i = 0; i < (MAXLEN + 1); ++i)
		lenarr[i] = 0;

	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t' || c == '\n')) {
			if (state == IN) {
				state = OUT;
				if (len > MAXLEN)
					len = MAXLEN + 1;
				++lenarr[len - 1];
				if (lenarr[len - 1] > max)
					max = lenarr[ len - 1];
				len = 0;
			}
		} else {
			state = IN;
			++len;
		}
	}

	for (i = max; i > 0; --i) {
		printf("%3d|", i);
		for (j = 0; j < (MAXLEN + 1); ++j) {
			putchar(' ');
			putchar(' ');
			if (lenarr[j] >= i)
				putchar(HIST_CHAR);
			else
				putchar(' ');
		}
		putchar('\n');
	}

	printf("   +");
	for (i = 0; i < (MAXLEN + 1); ++i) {
		printf("---");
	}
	putchar('\n');
	printf("    ");
	for (i = 0; i < MAXLEN; ++i) {
		printf("%3d", i + 1);
	}
	printf(">%2d", MAXLEN);
	putchar('\n');


	return 0;
}
