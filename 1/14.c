/* Exercise 1-14 */
/* VERTICAL */

#include <stdio.h>

#define IN  1
#define OUT 0
#define HIST_CHAR '*'
#define MAXLEN 256

/* print a histogram of the frequencies of different characters in input */
int main(void)
{
	int i, j, c, max;
	int lenarr[MAXLEN];

	max = 0;
	for (i = 0; i < MAXLEN; ++i)
		lenarr[i] = 0;

	while ((c = getchar()) != EOF)
		if (++lenarr[c] > max)
			max = lenarr[c];

	for (i = max; i > 0; --i) {
		printf("%3d|", i);
		for (j = 0; j < MAXLEN; ++j) {
			if (lenarr[j] > 0) {
				putchar(' ');
				if (lenarr[j] >= i)
					putchar(HIST_CHAR);
				else
					putchar(' ');
			}
		}
		putchar('\n');
	}

	printf("   +");
	for (i = 0; i < MAXLEN; ++i)
		if (lenarr[i] > 0)
			printf("--");
	putchar('\n');
	printf("    ");
	for (i = 0; i < MAXLEN; ++i) {
		if (lenarr[i] > 0) {
			if (i == '\t')
				printf("\\t");
			else if (i == '\n')
				printf("\\n");
			else
				printf(" %c", i);
		}
	}
	putchar('\n');

	return 0;
}
