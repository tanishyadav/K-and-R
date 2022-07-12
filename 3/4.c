/* Exercise 3-4 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	char out[100];
	itoa(INT_MIN, out);
	printf("%s\n", out);
	return 0;
}

void itoa(int n, char s[])
{
	int i;
	unsigned int n2;

	n2 = (n < 0) ? -n : n;
	i = 0;
	do {
		s[i++] = n2 % 10 + '0';
	} while ((n2 /= 10) > 0);
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int length = strlen(s);
	int c, i, j;

	for (i = 0, j = length - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
