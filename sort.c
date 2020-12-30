#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int partition(int *A, int left, int right)
{
        int j,i,t,pivot;
        pivot = A[right];
        i = left-1;
        for(j=left; j<right; j++ )
        {
                if ( A[j] < pivot )
                {
                        i++;
                        t = A[j];
                        A[j] = A[i];
                        A[i] = t;
                }
        }
        i++;
        A[right] = A[i];
        A[i] = pivot;
        return i;
}
void sort(int *A, int l, int r)
{
        if ( l < r )
        {
                int q = partition(A,l,r);
                sort(A, l, q-1);
                sort(A, q+1, r);
        }
}
int isIn(int s[], int idx, int element)
{
	int i;
	for(i = 0; i < idx; i++)
	{
		if(s[i] == element)
			return 0;
	}
	return 1;
}
int main(void)
{
	int std, hw;
	int **arr;
	int i, j;
	int *level;
	int *high;
	int *s;
	int idx = 0;

	scanf("%d %d", &hw, &std);

	arr = (int**)malloc(sizeof(int*) * std);

	for(i = 0; i < std; i++) 
		arr[i] = (int*)malloc(sizeof(int) * hw);

	level = (int*)malloc(sizeof(int) * hw);
	high = (int*)malloc(sizeof(int) * hw);
	s = (int*)malloc(sizeof(int) * hw);

	for(i = 0; i < std; i++)
	{
		for(j = 0; j < hw; j++)
			scanf("%d", &arr[i][j]);
	}
	
	for(i = 0; i < hw; i++)
		level[i] = 0;

	for(i = 0; i < hw; i++)
	{
		for(j = 0; j < std; j++)
			level[i] += arr[j][i];
	}
	
	for(i = 0; i < hw; i++)
		high[i] = level[i];

	sort(level, 0, hw - 1);

	for(i = 0; i < hw; i++)
	{
		for(j = 0; j < hw; j++)
		{
			if(level[i] == high[j])
			{
				if(isIn(s, idx, j + 1) == 1)
					s[idx++] = j + 1;
				else
					continue;
			}

			if(idx >= hw)
				break;
		}
	}
	for(i = 0; i < hw; i++)
		printf("%d ", level[i]);
	for(i = 0; i < hw; i++)
		printf("%d ", s[i]);
}