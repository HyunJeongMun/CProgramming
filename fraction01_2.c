/* Q02_01
	(���� ������.) �����ذ��� ������ ���� ���ð� �м� ����� �� ������ �Ǽ��� �Ͽ� ����� �ȴ�. 
	�츮�� �˰� �ִ� �м��� ����(���)�� a/b + c/d = (ad + bc)/bd �ε� 
	������ ���� ���ø� a/b + c/d = (ad + bc) / (b + d) ���� ����� �Ѵ�. 
	�׷��� �ű��ϰԵ� ������ ����� ������ ���� �츮�� �˴� ��� �״�� �Ѵ�.

	ak/bk = a/b (where k > 2, and a, b�� ���μ�).

	(1)�� �ҽ� �ڵ带 �̿��Ͽ� ������ ����� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	(�Է�) 3 5		(���) 17 9
	(�Է�) 1 4		(���) 1 1
	(�Է�) 6 10		(���) 17 9
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