/* Exercise 4-1 */

#include <stdio.h>
#include <string.h>

int strrindex(char source[], char searchfor[]);

int main(void)
{
	char searchin[] = "hello hi dude hi how do you do";
	char searchfor[] = "hi";
	printf("%s : %s : %d\n", searchin, searchfor, strrindex(searchin, searchfor));
	return 0;
}

int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s) - strlen(t); i >= 0; i--) {
		for (j = i, k = 0; t[k] != 0 && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
