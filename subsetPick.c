/* Q03
	(뽑기-등차수열) 문제해결기법 교수는 임의의 오름차순으로 정렬된 n개의 양수의 집합이 있다. 
	그곳에서 특정한 조건을 만족하는 부분집합의 개수를 세고 싶어졌다. 
	그 조건은 다음과 같다.

	(1) 부분집합의 원소의 개수는 L이다. (L을 등차수열의 길이라고 하자.)
	(2) 부분집합의 L개의 숫자들을 오름차순으로 정렬하였을 때 공차가 Z인 등차수열을 이룬다.

	예를 들어, 1,3,4,5,6,8,9,11에서 길이가 3이고 공차가 2인 등차수열을 만족하는 부분집합은
	(1,3,5), (4,6,8) 이므로 이 조건을 만족하는 부분집합의 개수는 2이다. 
	이와 같이 임의의 오름차순으로 정렬된 양수의 집합을 입력받은 후에 길이가 L이고 공차가 Z인 등차수열을 
	만족하는 부분집합의 개수를 출력해주는 프로그램을 작성하시오. 
	입력받을 숫자는 최대 1000개이며 같은 수가 두 번 입력되지 않는다. L은 4이상 300미만이며 Z는 2이상 10미만이다. (조합)
	
	(입력)	8 (입력할 숫자의 개수는 8)
			1 3 4 5 6 8 9 11 (8개의 숫자, 오름차순)
			3 2 (길이가 3이고 공차가 2인)
	(출력)	2
	(입력)	9 (입력할 숫자의 개수는 9)
			1 2 3 6 8 9 13 15 17
			6 3 (길이가 6이고 공차가 3인)
	(출력)	0 (위 조건을 만족하는 수열은 없음)
	(입력)	12 (입력할 숫자의 개수는 9)
			1 3 4 5 6 7 8 9 11 12 15 16
			3 3 (길이가 3이고 공차가 3인)
	(출력)	5
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

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index
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