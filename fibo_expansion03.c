#include <stdio.h>
int fibo(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int countFibo(int n, int count)
{
    if(fibo(count) <= n)
        return countFibo(n, count + 1);
    else if(n == 1)
        return 2;
    else
        return count;
}
int sumFibo(int n)
{
	if(n > 0)
		return fibo(countFibo(n, 0)) + sumFibo(n - fibo(countFibo(n, 0) - 1));
	else
		return 0;
}

int main(void)
{
	int num;

	scanf("%d", &num); // 학생 수 입력
    
    printf("%d", sumFibo(num));

}