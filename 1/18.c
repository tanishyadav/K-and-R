/* Exercise 1-18 */

/* print input lines with trailing spaces and tabs removed */

#include <stdio.h>

#define MAX 1000

int main(void)
{
	int c;
	int d;
	int l;          /* last character printed */
	int i;
	char s[MAX + 1];

	l = '\n';

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			s[0] = c;
			for (i=1; i<MAX && ((d=getchar())==' '||d=='\t'); ++i)
				s[i] = d;
			if (i == MAX) {
				/*
				 * If we have more than MAX consecutive tabs and
				 * spaces in a line, flush the currently stored
				 * spaces and tabs
				 */
				s[i] = '\0';
				printf("%s", s);
			} else if (d == '\n') {
				if (l != '\n') {
					l = d;
					putchar(d);
				}
			} else if (d == EOF) {
				;
			} else {
				s[i] = '\0';
				printf("%s", s);
				putchar(d);
			}
		} else {
			l = c;
			putchar(c);
		}
	}

	return 0;
}
