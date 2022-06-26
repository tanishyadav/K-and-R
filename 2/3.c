/* Exercise 2-3 */

#include <stdio.h>

int htoi(char s[]);

int main(void)
{
	printf("%d\n", htoi("12"));
	printf("%d\n", htoi("ab14"));
	printf("%d\n", htoi("AB14"));
	printf("%d\n", htoi("0xab14"));
	printf("%d\n", htoi("0xAB14"));
	printf("%d\n", htoi("0Xab14"));
	printf("%d\n", htoi("0XAB14"));
	printf("%d\n", htoi("0AB14"));
	printf("%d\n", htoi("0AB140"));
	printf("%d\n", htoi("0ABa140f"));
	printf("%d\n", htoi("abcdef"));
	printf("%d\n", htoi("mnabcdef"));
	printf("%d\n", htoi("abcmndef"));
	printf("%d\n", htoi("abcdefmn"));

	return 0;
}

int htoi(char s[])
{
	int n;
	int i;

	i = n = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	while (1) {
		if (s[i] >= '0' && s[i] <= '9')
			n = n*16 + s[i]-'0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = n*16 + s[i]-'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = n*16 + s[i]-'A' + 10;
		else
			return n;
		++i;
	}

	return n;
}
