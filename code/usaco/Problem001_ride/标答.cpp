#include <stdio.h>
#include <ctype.h>
// �˴�Ӧ��ѧϰ�������õ�hash˼�� 
int
hash(char *s)
{
	int i, h;

	h = 1;
	// �˴�Ӧ��ѧϰ��isalpha���÷� 
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

	// �˴�Ӧ��ѧϰfgets�÷� 
	fgets(comet, sizeof comet, in);
	fgets(group, sizeof group, in);

	if(hash(comet) == hash(group))
		fprintf(out, "GO\n");
	else
		fprintf(out, "STAY\n");
	exit (0);
}
