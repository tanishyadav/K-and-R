/* Exercise 1-8 */

#include <stdio.h>

/* count blank, tabs, and newlines */

int main(void)
{
	int c;
	long nb, nt, nl;

	nb = 0;
	nt = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}

	printf("Blanks: %ld Tabs: %ld Lines: %ld\n", nb, nt, nl);

	return 0;
}
