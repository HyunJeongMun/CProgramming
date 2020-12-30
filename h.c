#include <stdio.h>
#include <stdlib.h>
long long H(long long n, long long *F)
{
        long long ret = 0; 
		long long i = 0;
		long long k;
        
		if(n == 1) return 1;

        for(i = 1; i < n; i++)
        {
			k = n - i;
            if (F[i] == 0)
                    F[i] = H(n - k, F);
            ret = ret + F[i] * k;
		}

        return ret;
}
int main(void)
{
    long long n;
    long long *F;
    long long i;

	scanf("%lld", &n);
    
	F = (long long*) malloc(sizeof(long long)*(n + 1));
    
	for(i = 0;i < n + 1;i++)
            F[i] = 0;

    printf("%lld", H(n,F));
    free(F);
}