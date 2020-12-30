#include <stdio.h>
#include <string.h>

/*
• 흥민이는 “3의 배수”라는 새로운 게임을 만들어서 친구들과 여가 시간을 보내기 로 했다. 게임의 룰은 다음과 같다.
• (1) 숫자를 3부터 시작해서 3의 배수를 차례로 이야기한다. 첫 번째 사람은 3, 두 번째 사람은 6, 세 번째 사람은 9를 말한다.
• (2) 10보다 큰 3의 배수는 한 자리 씩 끊어서 말한다. 네 번째 사람은 1, 다섯 번째 사람은 2, 여섯 번째 사람은 다시 1, 일곱 번째 사람은 5를 말한다.
이런 순서로 게임을 진행하면
3 6 9 1 2 1 5 1 8 2 1 2 4 2 7 3 0 ...
의 순서로 숫자를 말하게 된다.
• 이렇게 숫자를 외치면서 즐거운 시간을 보내다가 문득 N 번째 사람은 어떤 숫자 를 말하게 될지 궁금해졌다. 
이것을 계산하여 출력해 주는 프로그램을 작성하시오. 
입력하는 숫자 N은 자연수이고 10만보다는 작다

*/

int len(int num) {
	// 자리수 구하기
	int cnt = 1;
	while (1) {
		num /= 10;
		if (num == 0)	return cnt;
		cnt++;
	}
}

int main(void) {
	int num;
	int game = 0;
	int sumLen = 0;
	int i;
	printf("Enter the number : ");
	scanf("%d", &num);

	while (1) {
		game += 3;

		sumLen += len(game);

		if (num <= sumLen) {
			for (i = 0; i < sumLen - num; i++) {
				game /= 10;
			}

			printf("%d번째 %d\n", num, game % 10);
			break;
		}
	}
}