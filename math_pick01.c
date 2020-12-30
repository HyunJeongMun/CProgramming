/*

1부터 임의의 N보다 같거나 작은 항까지 연속되어 있는 수와 +/-를 이용하여 만들 수 있는 수식 중에서 합이 N으로 계 산되는 수식은 복수개가 될 것이다. 즉 N을 6으로 계산되는 수식은 아래와 같으며
+1 +2 +3 = 6
+1 –2 +3 + 4 = 6그 수식의 개수는 2이다.
• 하나의 예를 더 보면 4를 N으로 할 경우 다음의 수식이 가능하며
+1 +2 –3 +4 = 4
-1 +2 +3 = 4
-1 –2 +3 +4 = 4
이며 그 수식의 개수는 3이다. N을 입력하였을 때 항의 개수가 N보다 작거나 같은 수식 중에서 합이 N으로 계산되는 수 식의 개수를 구하시오.
• 입력) 6
• 출력) 2 (2개의 식이 가능)
• 입력) 4 (→ N이 4임)
• 출력) 3 (3개의 식이 가능)
• 입력) 9
• 출력) 27

*/

#include <stdio.h>
int count = 0;
void pick(int n, int items[], int bucket[], int k, int topick, int numSum)
{
	int i, j, lastIndex, small;
	int sum;

	if(topick == 0)
	{
		sum = 0;
		for(i = 0; i < k; i++)
		{
			if(items[bucket[i]] == '+')
				sum += (i + 1);
			else
				sum -= (i + 1);
		}

		if(sum == numSum)
			count++;

		return ;
	}

	lastIndex = k - topick - 1;
	
	small = 0;

	for(i = small; i < n; i++)
	{
		bucket[lastIndex + 1] = i;
		pick(n, items, bucket, k, topick - 1, numSum);
	}
}

int main(void)
{
	int n;
	int items[2] = {'+','-'};
	int bucket[100]; // 뽑은 원소를 담는 배열
	int numSum;

	printf("Enter a number : ");
	scanf("%d", &n);
	 
	numSum = n;
	while(n >= 1){
		pick(2, items, bucket, n, n, numSum);
		n--;
	}

	printf("%d", count);
}