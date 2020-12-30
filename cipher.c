//암호화 - 문자와 숫자를 이용한 암호문
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int isIn(char *k, char c)
{
	int i;

	for(i = 0; i < strlen(k); i++)
	{
		if(k[i] == c)
			return 1;
	}

	return 0;
}
void remove_duplicated_char(char* word) 
{
	int i, idx = 0;
	char *copyWord;
	copyWord = (char*)malloc(sizeof(char) * strlen(word));

	for(i = 0; i < strlen(word); i++)
	{
		if(isIn(copyWord, word[i]) == 0)
			copyWord[idx++] = word[i];
	}

	copyWord[idx] = '\0';
	strcpy(word, copyWord);

}
void makeCode(char code[], char key[], int dist)
{
	int i, idx = dist;
	char copyCode[27];
	char c;

	for(i = 0; i < strlen(key); i++)
		copyCode[idx++] = key[i];

	c = 'A';
	for(i = idx; idx < strlen(code); i++)
	{
		if(c > 'Z')
			c = c - 'Z' + ('A' - 1);

		if(isIn(copyCode, c) == 0)
			copyCode[idx++] = c;
		
		c += 1;
	}

	copyCode[idx] = '\0';
	idx = 0;
	for(i = 0; idx < dist; i++)
	{
		if(c > 'Z')
			c = c - 'Z' + ('A' - 1);

		if(isIn(copyCode, c) == 0)
			copyCode[idx++] = c;

		c += 1;
	}

	strcpy(code, copyCode);
}
void encode(char code[], char s[], char e[])
{
	int i;
	int numIdx;

	for(i = 0; i < strlen(s); i++)
	{
		if(isupper(s[i]))
		{
			numIdx = s[i] - 'A';
			e[i] = code[numIdx];
		}
		else
			e[i] = s[i];
	}

	e[i] = '\0';
} 
int main(void)
{
	char key[40];
	int distance;
	int i;
	char code[27];
	char str[80];
	char encodedStr[80];

	printf("Enter a key to use for encoding : ");
	scanf("%s", key);

	remove_duplicated_char(key);
	printf("key = %s\n", key);

	for(i = 0; i < 26; i++)
		code[i] = 65 + i;
	code[i] = '\0';

	printf("Enter a distance for encoding : ");
	scanf("%d", &distance);

	printf("----------------------------------\n");
	printf("alphabet :\t\t%s\n", code);
	makeCode(code, key, distance);
	printf("\nencoded :\t\t%s\n", code);
	printf("\n----------------------------------\n");

	printf("\nEnter a sentence to encode : ");
	fflush(stdin);
	gets(str);

	printf("original sentence :\t\t%s\n", str);
	encode(code, str, encodedStr);
	printf("encoded sentence :\t\t%s\n", encodedStr);
}