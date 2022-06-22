/* Exercise 2-2 */

/*
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 */

#include <stdio.h>

int main(void)
{
	int i;
	int c;
	int lim=100;
	char s[100];

	for (i=0; (i<lim-1) * ((c=getchar()) != '\n') * (c != EOF); ++i)
		s[i] = c;

	s[i] = '\0';
	printf("%s", s);
}
