/* Exercise 3-2 */

#include <stdio.h>

#define MAX 100
void escape(char s[], char t[]);
void capture(char s[], char t[]);

int main(void)
{
	char escape_input[] = "\t\tasb\\ct\t\tafij\n\tssd\n";
	char escape_output[MAX];
	char capture_output[MAX];
	escape(escape_output, escape_input);
	capture(capture_output, escape_output);
	printf("Escape input:\n%s\n", escape_input);
	printf("Escape output/Capture input:\n%s\n", escape_output);
	printf("Capture output:\n%s\n", capture_output);
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}

void capture(char s[], char t[])
{
	int i, j;
	char p;

	p = '\0';
	for (i = j = 0; t[i] != '\0'; i++) {
		if (p == '\\')
			switch (t[i]) {
			case 't':
				s[j-1] = '\t';
				break;
			case 'n':
				s[j-1] = '\n';
				break;
			default:
				s[j++] = t[i];
				p = t[i];
				break;
			}
		else {
			s[j++] = t[i];
			p = t[i];
		}
	}
	s[j] = '\0';
}
