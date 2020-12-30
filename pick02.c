#include <stdio.h>
#include <stdlib.h>
int total = 0;
int min = 100;
void pick(int n, int items[], int bucket[], int k, int topick)
{
	int i, lastIndex, small;
	int sumA;
	int sumB;
	int gap;
	if(topick == 0)
	{
		sumA = 0;
		for(i = 0; i < k; i++)
			sumA += items[bucket[i]];

		sumB = total - sumA;
		if(sumA > sumB)
			gap = sumA - sumB;
		else
			gap = sumB - sumA;

		if(min > gap)
			min = gap;
		
		return;
	}

	lastIndex = k - topick - 1;
	
	if(lastIndex == -1)
		small = 0;
	else
		small = bucket[lastIndex] + 1;

	for(i = small; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(n, items, bucket, k, topick - 1);
	}
}
int main(void)
{
	int i;
	int n;
	int *items, *bucket;

	scanf("%d", &n);
	items = (int*)malloc(sizeof(int) * n);

	fflush(stdin);
	for(i = 0; i < n; i++)
		scanf("%d", &items[i]);

	bucket = (int*)malloc(sizeof(int) * (n / 2));
	
	for(i = 0; i < n; i++)
		total += items[i];

	pick(n, items, bucket, n / 2, n / 2);
	printf("%d", min);
}