#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

"abcabcdede"와 같은 경우, 문자를 2개 단위로 자르면 ab/ca/bc/de/de이므로 이를 압축하면 "abcabc2de”가
되지만, 3개 단위로 자른다면 abc/abc/ded/e이므로 "2abcdede”가 되어 3개 단위가 가장 짧은 압축 방법이
됩니다. (단위로 자르고 마지막에 남는 문자들은 그대로 붙여주면 된다)
압축할 문자열 s가 매개변수로 주어질 때, 위에 설명한 방법으로 1개 이상 단위로 문자열을 잘라 압축하여
표현한 문자열 중 *가장 짧은 것의 길이를 return *하도록 함수를 완성해주세요.
예 #1
aabbaccc
7
예 #2
ababcdcdababcdcd
9
예 #3
abcabcdede
8
예 #4
abcabcabcabcdededededede
14
예 #5
xababcdcdababcdcd
17
예 #6
aaaaaaaaaa
3
위의 실행 예에 대한 설명
- 입출력 예 #1 문자열을 1개 단위로 잘라 압축했을 때 "2a2ba3c"가 되며 길이는 7로 가장 짧습니다.
- 입출력 예 #2 문자열을 8개 단위로 잘라 압축했을 때 가장 짧습니다.
- 입출력 예 #3 문자열을 3개 단위로 잘라 압축했을 때 가장 짧습니다.
- 입출력 예 #4 문자열을 2개 단위로 자르면 "abcabcabcabc6de” 가 됩니다. 문자열을 3개 단위로 자르면
"4abcdededededede” 가 됩니다. 문자열을 4개 단위로 자르면 "abcabcabcabc3dede” 가 됩니다. 문자열을 6개
단위로 자를 경우 "2abcabc2dedede”가 되며, 이때의 길이가 14로 가장 짧습니다.
- 입출력 예 #5 문자열은 제일 앞부터 정해진 길이만큼 잘라야 합니다. 따라서 주어진 문자열을 x / ababcdcd /
ababcdcd 로 자르는 것은 불가능 합니다. 이 경우 어떻게 문자열을 잘라도 압축되지 않으므로 가장 짧은 길이는
17이 됩니다.
- 입출력 예 #6: 1개 단위로 짤라서 얻은 11a가 압축된 문자열이고 가장 짧다. 길이는 3. (문제 1-1, 1-2에서의
다음과 같은 제한을 변경한다.
연속적으로 중복되는 회수는 10 미만라고 하자
-> 중복 회수는 제한이 없다!)
제한사항
이 문제를 포함하여 이 후 문제들의 제한 사항은 다음과 같습니다. → s의 길이는 1 이상 1,000 미만입니다.
→ s는 알파벳 소문자로만 이루어져 있습니다.

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