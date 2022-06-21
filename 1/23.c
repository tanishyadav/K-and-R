/* Exercise 1-23 */

#include <stdio.h>

#define NA      -1
#define IN      1
#define OUT     0
#define QUOTE   '\''
#define DQUOTE  '"'
#define SLASH   '/'
#define BSLASH  '\\'
#define ASTRSK  '*'

int main(void)
{
	int c;
	char l;
	char q;
	int state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ASTRSK && state == IN) {
			l = NA;
			while ((c = getchar()) != EOF && (c != SLASH || l != ASTRSK))
				l = c;
			state = OUT;
		} else {
			if (state == IN) {
				putchar(SLASH);
				state = OUT;
			}
			if (c == QUOTE || c == DQUOTE) {
				l = NA;
				q = c;
				putchar(c);
				while ((c = getchar()) != EOF && (c != q || l == BSLASH)) {
					putchar(c);
					l = c;
				}
				if (c != EOF)
					putchar(c);
			} else if (c == SLASH) {
				state = IN;
			} else {
				putchar(c);
			}
		}
	}
	if (state == IN)
		putchar(SLASH);

	return 0;
}
