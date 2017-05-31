#include <stdio.h>
#include <ctype.h>
// 此处应该学习到这是用的hash思想 
int
hash(char *s)
{
	int i, h;

	h = 1;
	// 此处应该学习到isalpha的用法 
	for(i=0; s[i] && isalpha(s[i]); i++)
		h = ((s[i]-'A'+1)*h) % 47;
	return h;
}

void
main(void)
{
	FILE *in, *out;
	char comet[100], group[100];  /* bigger than necessary, room for newline */

	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");

	// 此处应该学习fgets用法 
	fgets(comet, sizeof comet, in);
	fgets(group, sizeof group, in);

	if(hash(comet) == hash(group))
		fprintf(out, "GO\n");
	else
		fprintf(out, "STAY\n");
	exit (0);
}
