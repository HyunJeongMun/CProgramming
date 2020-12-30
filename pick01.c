/* Q04
	(�̱�) �����ذ��� ������ ������ ���� ���α׷��� �ۼ��Ϸ��� �Ѵ�. 
	�� ���α׷��� n���� ���ڵ�� �� ���� ���� K, S�� �Է¹޴´�. 
	�׸��� n���� ���ڵ� �߿��� K���� ���ڵ��� ��� (���� ���ڴ� �� �� �� �� ����.) �� ���� S�� �Ǵ� ����� ���� ����Ѵ�. 
	7���� ���� 10, 20, 30, 40, 50, 60, 70�� 2���� ��� �� ���� 90�� �Ǵ� ���� (20,70), (30,60), (40,50) �̸� ���� ����� ���� 3�̴�. 
	�̷��� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�. #����

	(�Է�) 7 (�Է��� ������ ������ 7)
	20 10 30 70 60 50 40 (7���� ����)
	2 90 (2���� ��� �� ���� 90�� ���)
	(���) 3
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

	lastIndex = bucketSize - k - 1; // ���� �ֱٿ� ���� ���� ����� ��ġ index
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