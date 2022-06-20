/* Exercise 1-22 */

/*
 * enfold: fold long input lines into two or more shorter lines after the last
 * non-blank character that occurs before the n-th column of input.
 * NOTE-1: In the interests of brevity, this program considers tab ('\t') like any
 * other non-blank character.
 * NOTE-2: All lines are assumed to end in a newline ('\n').
 */

#include <stdio.h>

#define NO              -1
#define MAX             80      /* includes newline */
#define LN_CONT_CHAR    '-'     /* line continuation character */

/*
 * println: print characters till index i (inclusive) of line.
 */
void println(char line[], int i);
/*
 * shift2start: move characters from index i to j (inclusive) of line to the
 * start.
 */
void shift2start(char line[], int i, int j);

int main(void)
{
	int c;
	int i;
	int b;          /* index of last blank encountered */
	char line[MAX];

	b = NO;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			println(line, i-1);
			putchar(c);
			i = 0;
			b = NO;
		} else {
			line[i] = c;
			if (c == ' ')
				b = i;
			if (i == MAX-1) {
				if (b == NO) {
					println(line, i-2);
					putchar(LN_CONT_CHAR);
					putchar('\n');
					line[0] = line[i-1];
					line[1] = line[i];
					i = 2;
				} else {
					println(line, b-1);
					putchar('\n');
					shift2start(line, b+1, i);
					i = i - b;
					b = NO;
				}
			} else {
				++i;
			}
		}
	}

	return 0;
}

void println(char l[], int i)
{
	int j;
	for (j = 0; j <= i; ++j) {
		putchar(l[j]);
	}
}

void shift2start(char l[], int i, int j)
{
	int k;

	k = 0;
	while (i <= j) {
		l[k] = l[i];
		++k;
		++i;
	}
}
