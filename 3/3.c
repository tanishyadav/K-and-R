/* Exercise 3-3 */

#include <stdio.h>

#define MAX 1000

/*
 * expand: expand shorthand notations in s1 into the equivalent complete list in
 * s2.
 *
 * a-b          ab
 * a-d          abcd
 * d-a          dcba
 * a-b-c        abc
 * a-d-f        abcdef
 * a-d-a        abcdcba
 * -a-c         -abc
 * a-c-         abc-
 * a-a          a-a
 *
 * NOTE: The list depends directly on the character set. So things like
 *       .-2            ./012
 *       are possible on an ASCII machine.
 */
void expand(char s1[], char s2[]);

int main(void)
{
	char out[1000];
	expand("a-z-a", out);
	printf("%s\n", out);
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j;
	int close;

	for (i = j = 0; s1[i] != '\0'; i++) {
		if (s1[i] != '-' || i == 0 || s1[i+1] == '\0' || s1[i-1] == s1[i+1]) {
			s2[j++] = s1[i];
			continue;
		}
		close = (s1[i-1] < s1[i+1]) ? 1 : -1;
		while (s2[j-1] != s1[i+1]) {
			s2[j] = s2[j-1]+close;
			j++;
		}
		i++;
	}
	s2[j] = '\0';
}
