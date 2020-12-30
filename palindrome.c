#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char s[])
{
	// 코드 입력
	
	int length = strlen(s);
	int i = 0;
	int k = length - 1;

	while(i < length / 2)
	{
		if(isalpha(s[i]) && isalpha(s[k]))
		{
			if(toupper(s[i]) != toupper(s[k]))
				return 0;
            
            i++;
            k--;
        }
		else if(s[i] == ' ')
            i++;
		else if(s[k] == ' ')
		    k--;
		else if(s[i] != s[k])
			return 0;
	}

	return 1;
}

int main(void) // main함수는 변경하지 말라
{
	char str[30];

	gets(str); // 공백문자를 포함한 문자열을 읽으려면 gets를 써야함

	printf("%d\n", isPalindrome(str)); // 0 또는 1을 출력
}