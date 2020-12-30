#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
�Է°Ÿ���ŭ �����ؼ� ���ĺ� ������� ��
*/
int main(void)
{
	char code[27], encoded[27];
	int i, idx;
	int distance;

	scanf("%d", &distance);

	for(i = 0; i < 26; i++)
		code[i] = 65 + i;

	code[i] = '\0';

	idx = distance - 1;
	i = 0;
	while(idx < 26)
	{
		encoded[idx] = code[i];
		idx += distance;
		i++;
	}

	idx = 0;
	for(idx = 0; idx < 26; idx++)
	{
		if(!(encoded[idx] <= 'Z' && encoded[idx] >= 'A'))
			encoded[idx] = code[i++];
	}

	encoded[26] = '\0';

	printf("%s", encoded);
}