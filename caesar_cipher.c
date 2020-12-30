//시저 암호
/*
 시저 암호로 입력받은 문장을 암호화하여 출력하라. 
 - distance를 입력 받는다 
 - 문제를 단순화하기 위해 대문자만 암호화하기로 한다. (즉 대문자 이외의 문자들은 그대로) 
 - 문장을 입력 받아 암호화해서 출력한다.
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