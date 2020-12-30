/* Q02_01
	(술이 문제야.) 문제해결기법 교수는 술을 마시고 분수 계산을 할 때마다 실수를 하여 놀림감이 된다. 
	우리가 알고 있던 분수의 덧셈(통분)은 a/b + c/d = (ad + bc)/bd 인데 
	교수는 술을 마시면 a/b + c/d = (ad + bc) / (b + d) 으로 계산을 한다. 
	그런데 신기하게도 교수의 약분은 다음과 같이 우리가 알던 방식 그대로 한다.

	ak/bk = a/b (where k > 2, and a, b는 서로소).

	(1)의 소스 코드를 이용하여 교수가 통분을 하는 프로그램을 작성하시오.
	
	(입력) 3 5		(출력) 17 9
	(입력) 1 4		(출력) 1 1
	(입력) 6 10		(출력) 17 9
*/
#include <stdio.h>
int gcd(int m,int n)
{
	if(m < n)
	{
		int tmp=m;
		m = n;
		n = tmp;
	}
	if (m % n==0)
		return n;
	else
		return gcd(n,m%n);
}

int main(void)
{
	int a, b;
	int c, d;
	int k;
	int rsM, rsN;

	printf("Enter the number1 : ");
	scanf("%d %d", &a, &b);
	k = gcd(a, b);
	a /= k;
	b /= k;

	printf("Enter the number2 : ");
	scanf("%d %d", &c, &d);
	k = gcd(c, d);
	c /= k;
	d /= k;

	rsM = a * d + b * c;
	rsN = b + d;
	k = gcd(rsM, rsN);
	rsM /= k;
	rsN /= k;

	printf("result = %d %d\n", rsM, rsN);
}