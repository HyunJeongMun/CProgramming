/* Q03
	(�̱�-��������) �����ذ��� ������ ������ ������������ ���ĵ� n���� ����� ������ �ִ�. 
	�װ����� Ư���� ������ �����ϴ� �κ������� ������ ���� �;�����. 
	�� ������ ������ ����.

	(1) �κ������� ������ ������ L�̴�. (L�� ���������� ���̶�� ����.)
	(2) �κ������� L���� ���ڵ��� ������������ �����Ͽ��� �� ������ Z�� ���������� �̷��.

	���� ���, 1,3,4,5,6,8,9,11���� ���̰� 3�̰� ������ 2�� ���������� �����ϴ� �κ�������
	(1,3,5), (4,6,8) �̹Ƿ� �� ������ �����ϴ� �κ������� ������ 2�̴�. 
	�̿� ���� ������ ������������ ���ĵ� ����� ������ �Է¹��� �Ŀ� ���̰� L�̰� ������ Z�� ���������� 
	�����ϴ� �κ������� ������ ������ִ� ���α׷��� �ۼ��Ͻÿ�. 
	�Է¹��� ���ڴ� �ִ� 1000���̸� ���� ���� �� �� �Էµ��� �ʴ´�. L�� 4�̻� 300�̸��̸� Z�� 2�̻� 10�̸��̴�. (����)
	
	(�Է�)	8 (�Է��� ������ ������ 8)
			1 3 4 5 6 8 9 11 (8���� ����, ��������)
			3 2 (���̰� 3�̰� ������ 2��)
	(���)	2
	(�Է�)	9 (�Է��� ������ ������ 9)
			1 2 3 6 8 9 13 15 17
			6 3 (���̰� 6�̰� ������ 3��)
	(���)	0 (�� ������ �����ϴ� ������ ����)
	(�Է�)	12 (�Է��� ������ ������ 9)
			1 3 4 5 6 7 8 9 11 12 15 16
			3 3 (���̰� 3�̰� ������ 3��)
	(���)	5
*/
#include <stdio.h>
#include <stdlib.h>
int count1 = 0;
int count2 = 0;
void pick(int n, int numbers[], int length, int torun, int d)
{
	int i, small;
	int index = 1;
	int buf[100];

	if(torun == 0)
		small = 0;
	else
		small = torun;
	
	buf[0] = numbers[small];
	for(i = small + 1; i < n; i++)
	{
		if(index == length)
		{
			count1++;
			break;
		}

		if(numbers[i] == (buf[index - 1] + d))
			buf[index++] = numbers[i];
		else
			continue;
	}

	if(torun == n - length + 1)
		return;
	else
		pick(n, numbers, length, torun + 1, d);
}

void topick(int items[], int n, int* bucket, int bucketSize, int k, int d) 
{
	int i, j, lastIndex;

	if(k == 0) 
	{
		for(i = 1; i < bucketSize; i++)
		{
			if(items[bucket[i]] != (items[bucket[i - 1]] + d))
				return;
		}

		count2++;
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
		topick(items, n, bucket, bucketSize, k - 1, d);
	}
}

int main(void)
{
	int n, length, d;
	int numbers[100];
	int i;
	int *picked;

	printf("Enter a number : ");
	scanf("%d", &n);

	picked = (int*)malloc(sizeof(int)*n);
	if(!picked)
		printf("Error in alloc\n");

	printf("Enter the numbers : ");
	for(i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	printf("Enter the Length and D : ");
	scanf("%d %d", &length, &d);

	pick(n, numbers, length, 0, d);
	printf("count1 = %d\n", count1);

	topick(numbers, n, picked, length, length, d);
	printf("count2 = %d\n", count2);
}