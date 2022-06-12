/* Exercise 1-17 */

/* print input lines longer than 80 chars */

#include <stdio.h>
#define MINLEN 80+1 /* We've to print input lines stictly longer than 80 */

int getln(char line[], int maxlen);

int main(void)
{
	int c, len;
	char line[MINLEN + 1];

	while ((len = getln(line, MINLEN+1)) > 0) {
		if (len == MINLEN ) {
			printf("%s", line);
			if (line[MINLEN-1] != '\n') {
				while ((c = getchar()) != EOF && c != '\n') {
					putchar(c);
				}
				if (c == '\n')
					putchar('\n');
			}
		}
	}

	return 0;
}

int getln(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
