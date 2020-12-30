/*Q05
	교수는 피보나치 함수를 (아주) 조금 확장한 3-보나치 수열을 혼자서 떠올리고 그 수열을 만들어가고 있다. 
	3-보나치 수열의 정의는 다음과 같다.

		- If n > 3, Fn = Fn-1 + Fn-2 + Fn-3
		- Otherwise, Fn = 1

	이 정의에 따라 Fn을 F1 , F2 , F3 의 다항식으로 전개할 수 있는데 이 때 F1 , F2 , F3 의 계수를 출력하는 프로그램을 작성하시오. 
	예를 들어, F4 = F3 + F2 + F1 이므로 F1 , F2 , F3의 계수는 각각 1, 1, 1이다.
			   F5 = F4 + F3 + F2 = 2F3 + 2F2 + F1이므로 F1 , F2 , F3의 계수는 각각 1, 2, 2이다.
			   F6 = F5 + F4 + F3 = 2F3 + 2F2 + F1 + F3 + F2 + F1 + F3 = 4F3 + 3F2 + 2F1 이므로 F1 , F2 , F3의 계수는 각각 2, 3, 4이다.
	(입력) 1		(출력) 1 0 0 (--> F1 , F2 , F3의 계수는 각 1, 1, 1)
	(입력) 2		(출력) 0 1 0 (--> F1 , F2 , F3의 계수는 각 0, 1, 0)
	(입력) 3		(출력) 0 0 1 (--> F1 , F2 , F3의 계수는 각 0, 0, 1)
	(입력) 4		(출력) 1 1 1 (--> F1 , F2 , F3의 계수는 각 1, 1, 1)
	(입력) 5		(출력) 1 2 2 (--> F1 , F2 , F3의 계수는 각 1, 2, 2)
	(입력) 6		(출력) 2 3 4 (--> F1 , F2 , F3의 계수는 각 2, 3, 4)
	(입력) 10		(출력) 24 37 44 (--> F1 , F2 , F3의 계수는 각 24, 37, 44)
*/
#include <stdio.h>

int three_fibo(int n, int f[])
{
	if(n == 1)
		return f[0] += 1;
	else if(n == 2)
		return f[1] += 1;
	else if(n == 3)
		return f[2] += 1;
	else
		return three_fibo(n - 1, f) + three_fibo(n - 2, f) + three_fibo(n - 3, f);
}
int main(void)
{
	int n;
	int f;
	int fb[3] = {0};

	printf("Enter a number : ");
	scanf("%d", &n);
	
	f = three_fibo(n, fb);

	printf("%d %d %d\n", fb[0], fb[1], fb[2]);
}