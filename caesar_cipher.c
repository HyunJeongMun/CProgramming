//���� ��ȣ
/*
 ���� ��ȣ�� �Է¹��� ������ ��ȣȭ�Ͽ� ����϶�. 
 - distance�� �Է� �޴´� 
 - ������ �ܼ�ȭ�ϱ� ���� �빮�ڸ� ��ȣȭ�ϱ�� �Ѵ�. (�� �빮�� �̿��� ���ڵ��� �״��) 
 - ������ �Է� �޾� ��ȣȭ�ؼ� ����Ѵ�.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	int distance;
	int i;
	char str[80];
	char encodedStr[80];

	printf("Enter a distance for encoding : ");
	scanf("%d", &distance);

	printf("----------------------------------\n");
	printf("alphabet :\t\t");
	for(i = 0; i < 26; i++)
		printf("%c ", 65 + i);

	printf("\nencoded :\t\t");
	for(i = 0; i < 26; i++)
	{
		if(i + 65 + distance <= 'Z')
			printf("%c ", 65 + i + distance);
		else
			printf("%c ", 65 + i + distance - ('Z' - 'A' + 1));
	}
	printf("\n----------------------------------\n");

	printf("\nEnter a sentence to encode : ");
	fflush(stdin);
	gets(str);

	for(i = 0; i < strlen(str); i++)
	{
		if(isupper(str[i]))
			encodedStr[i] = (str[i] - 'A' + distance) % 26 + 'A';
		else
			encodedStr[i] = str[i];
	}

	encodedStr[i] = '\0';

	printf("original sentence :\t\t%s\n", str);
	printf("encoded sentence :\t\t%s\n", encodedStr);
}