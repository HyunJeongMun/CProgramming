#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

"abcabcdede"�� ���� ���, ���ڸ� 2�� ������ �ڸ��� ab/ca/bc/de/de�̹Ƿ� �̸� �����ϸ� "abcabc2de����
������, 3�� ������ �ڸ��ٸ� abc/abc/ded/e�̹Ƿ� "2abcdede���� �Ǿ� 3�� ������ ���� ª�� ���� �����
�˴ϴ�. (������ �ڸ��� �������� ���� ���ڵ��� �״�� �ٿ��ָ� �ȴ�)
������ ���ڿ� s�� �Ű������� �־��� ��, ���� ������ ������� 1�� �̻� ������ ���ڿ��� �߶� �����Ͽ�
ǥ���� ���ڿ� �� *���� ª�� ���� ���̸� return *�ϵ��� �Լ��� �ϼ����ּ���.
�� #1
aabbaccc
7
�� #2
ababcdcdababcdcd
9
�� #3
abcabcdede
8
�� #4
abcabcabcabcdededededede
14
�� #5
xababcdcdababcdcd
17
�� #6
aaaaaaaaaa
3
���� ���� ���� ���� ����
- ����� �� #1 ���ڿ��� 1�� ������ �߶� �������� �� "2a2ba3c"�� �Ǹ� ���̴� 7�� ���� ª���ϴ�.
- ����� �� #2 ���ڿ��� 8�� ������ �߶� �������� �� ���� ª���ϴ�.
- ����� �� #3 ���ڿ��� 3�� ������ �߶� �������� �� ���� ª���ϴ�.
- ����� �� #4 ���ڿ��� 2�� ������ �ڸ��� "abcabcabcabc6de�� �� �˴ϴ�. ���ڿ��� 3�� ������ �ڸ���
"4abcdededededede�� �� �˴ϴ�. ���ڿ��� 4�� ������ �ڸ��� "abcabcabcabc3dede�� �� �˴ϴ�. ���ڿ��� 6��
������ �ڸ� ��� "2abcabc2dedede���� �Ǹ�, �̶��� ���̰� 14�� ���� ª���ϴ�.
- ����� �� #5 ���ڿ��� ���� �պ��� ������ ���̸�ŭ �߶�� �մϴ�. ���� �־��� ���ڿ��� x / ababcdcd /
ababcdcd �� �ڸ��� ���� �Ұ��� �մϴ�. �� ��� ��� ���ڿ��� �߶� ������� �����Ƿ� ���� ª�� ���̴�
17�� �˴ϴ�.
- ����� �� #6: 1�� ������ ©�� ���� 11a�� ����� ���ڿ��̰� ���� ª��. ���̴� 3. (���� 1-1, 1-2������
������ ���� ������ �����Ѵ�.
���������� �ߺ��Ǵ� ȸ���� 10 �̸���� ����
-> �ߺ� ȸ���� ������ ����!)
���ѻ���
�� ������ �����Ͽ� �� �� �������� ���� ������ ������ �����ϴ�. �� s�� ���̴� 1 �̻� 1,000 �̸��Դϴ�.
�� s�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.

*/

char* str_cut(char *s, int idx, int start){
	int i;
	char *cut = (char*)malloc(sizeof(char) * idx);

	for(i = 0; i < idx; i++)
		cut[i] = s[i + start];

	return cut;

}
int is_in(char *s, char *key, int start, int idx){
	int c = 0;
	int i, j;
	int end = strlen(s);
	
	for(i = start; i < end; i += idx){
		for(j = 0; j < idx != '\0'; j++){
			if(key[j] != s[i + j])
				return c;
		}

		c++;
	}

	return c;
}

int solution(char *s) {     
	int len;
	int lenght = strlen(s);
	int min = lenght;
	int count = 1;
	int same;
	char *key;
	int i;

	while(count <= lenght){
		len = 0;
		i = 0;

		while(i < lenght){
			key = str_cut(s, count, i);

			if(strlen(key) < count)
				len += strlen(key);
			else{

				same = is_in(s, key, i, count);

				if(same >1)
					len += (count + (1 + same / 10));
				else
					len += count;
			}

			i = i + count * same;
		}

		if(len < min)
			min = len;

		count++;
	}

	return min;

} 
int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("%d\n", solution(s));
}