//재귀 - memoization
// Hn = 1(if n = 0 or n = 1)
// Hn = H0 * Hn-1 + H1 * Hn-2 ... + Hn-1 * H0 (if n > 1)
#include <stdio.h>
#include <stdlib.h>
int H(int n, int *F)
{
        int ret = 0; 
		int i = 0;

        if( n == 0 || n == 1 ) 
			return 1;
       
		for(i = 0; i < n ; i++ )
        {
			if (F[i] == 0)
				F[i] = H(i,F);
			if (F[n - 1 - i] == 0 )
				F[n - 1 - i] = H(n - 1 - i, F);
			ret = ret + F[i] * F[n - 1 - i];
        }
        return ret;
}
int main(void)
{
	int n;
	int *M;
	int i;

	printf("Enter a number(> 0) : ");
	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * (n + 1)); // r행 동적 할당

	for(i = 0; i < n + 1; i++)
		M[i] = 0;

	printf("result = %d\n", H(n, M));

	free(M);
}