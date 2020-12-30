#include <stdio.h>
int fibo(int n);
int countFibo(int n, int count);
int main(void)
{
	int num;
	int n = 1;

	scanf("%d", &num);
    
    if(num == 1)
        printf("2");
	else
		printf("%d", fibo(countFibo(num, 0)));
    
    
}

int fibo(int n) // 재귀적으로 구현하지 않는다
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
        return 1;
    else
        return count;
}