/* Q04
	(뽑기) 문제해결기법 교수는 다음과 같은 프로그램을 작성하려고 한다. 
	이 프로그램은 n개의 숫자들과 두 개의 숫자 K, S를 입력받는다. 
	그리고 n개의 숫자들 중에서 K개의 숫자들을 골라서 (같은 숫자는 두 번 고를 수 없다.) 그 합이 S가 되는 경우의 수를 출력한다. 
	7개의 숫자 10, 20, 30, 40, 50, 60, 70에 2개를 골라 그 합이 90이 되는 경우는 (20,70), (30,60), (40,50) 이며 따라서 경우의 수는 3이다. 
	이러한 일을 수행하는 프로그램을 작성하시오. #조합

	(입력) 7 (입력할 숫자의 개수는 7)
	20 10 30 70 60 50 40 (7개의 숫자)
	2 90 (2개를 골라 그 합이 90인 경우)
	(출력) 3
*/

#include <stdlib.h>
#include <stdio.h>
int count = 0;
void pick(int items[], int n, int* bucket, int bucketSize, int k, int s) 
{
	int i, j, lastIndex;

	if(k == 0) 
	{
		int sum = 0;
		for(i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		
		if(s == sum)
			count++;

		return;
	}

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
	if(k == bucketSize)
		j = 0;
	else
		j = bucket[lastIndex] + 1;

	for(i = j; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(items, n, bucket, bucketSize, k - 1, s);
	}
}
int main(void)
{
	int numbers[100];
	int n, k, s, i;
	int *picked;
	
	printf("Enter a number : ");
	scanf("%d", &n);

	picked = (int*)malloc(sizeof(int)*n);
	if(!picked)
		printf("Error in alloc\n");

	printf("Enter the numbers : ");
	for(i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	printf("Enter the K and S : ");
	scanf("%d %d", &k, &s);

	pick(numbers, n, picked, k, k, s);

	printf("count = %d\n", count);

	free(picked);
}