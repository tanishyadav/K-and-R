/* Exercise 1-19 */

#include <stdio.h>
#define MAX 1000

void reverse(char string[], int len);
int getln(char string[], int len);

int main(void)
{
	char s[MAX];
	int len;

	while ((len = getln(s, MAX)) >= 0) {
		reverse(s, len);
		printf("%s\n", s);
	}

	return 0;
}

void reverse(char s[], int len)
{
	int i;
	char tmp;

	for (i = 0; i < len/2; ++i) {
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}
}

int getln(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	s[i] = '\0';

	/* flush extra line */
	if (i == lim - 1)
		while ((c = getchar()) != EOF && c != '\n')
			;

	if (i == 0 && c == EOF)
		i = -1;
	return i;
}
