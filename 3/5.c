/* Ecercise 3-5 */

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_BASE (10 + 26)

int itob(unsigned int n, char s[], int b);
char itoc(int n);
void reverse(char s[]);

int main(void)
{
	char s[MAX];

	itob(100, s, 2);
	printf("(100)2: %s\n", s);
	itob(100, s, 16);
	printf("(100)16: %s\n", s);
	itob(100, s, 36);
	printf("(100)36: %s\n", s);
	printf("(100)37: %d\n", itob(100, s, 37));

	return 0;
}

int itob(unsigned int n, char s[], int b)
{
	int i;
	if (b > MAX_BASE)
		return -1;

	i = 0;
	do {
		s[i++] = itoc(n % b);
	} while ((n /= b) > 0);
	s[i] = '\0';

	reverse(s);
	return 0;
}

char itoc(int n)
{
	return (n > 9) ? n-9+'a' : n+'0';
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
