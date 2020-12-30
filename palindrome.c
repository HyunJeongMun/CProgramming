#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char s[])
{
	// �ڵ� �Է�
	
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

int main(void) // main�Լ��� �������� ����
{
	char str[30];

	gets(str); // ���鹮�ڸ� ������ ���ڿ��� �������� gets�� �����

	printf("%d\n", isPalindrome(str)); // 0 �Ǵ� 1�� ���
}