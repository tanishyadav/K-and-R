/* Exercise 1-13 */
/* HORIZONTAL (EASY) */

#include <stdio.h>

#define IN  1
#define OUT 0
#define HIST_CHAR '*'
#define MAXLEN 10

/* print a histogram of length of words in input */
int main(void)
{
	int i, j, c, state, len;
	int lenarr[MAXLEN + 1];

	state = OUT;
	len = 0;
	for (i = 0; i < (MAXLEN + 1); ++i)
		lenarr[i] = 0;

	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t' || c == '\n')) {
			if (state == IN) {
				state = OUT;
				if (len > MAXLEN)
					++lenarr[MAXLEN];
				else
					++lenarr[len - 1];
				len = 0;
			}
		} else {
			state = IN;
			++len;
		}
	}

	for (i = 0; i < (MAXLEN + 1); ++i) {
		if (i == MAXLEN)
			printf("|>%2d| ", MAXLEN);
		else
			printf("|%3d| ", i + 1);

		for (j = 0; j < lenarr[i]; ++j) {
			putchar(HIST_CHAR);
		}
		putchar('\n');
	}

	return 0;
}
