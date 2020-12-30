/*
3번 문제의 프로그램을 이용하여 다음과 같은 프로그램을 추가적으로 작성하고 싶다. 1
부터 연속되어 있는 수와 +/-를 이용하여 만들 수 있는 수식 중에서 임의의 N으로 계산 되는 수식은 복수개가 될 것이다. N을 입력하였을 때 N으로 계산되는 수식들 중에서 가 장 길이가 짧은 수식의 항의 개수 n을 구하는 문제이다.
• 즉 N이 3으로 계산되는 수식은 아래와 같이 복수개가 나올 수 있다.
+1 +2 = 3
-1 +2 +3 +4 –5 = 3
• 첫 번째 수식이 길이가 짧고 항의 개수는 2이다.
• 입력이 6일 경우는 +1 +2 +3 = 6, +1 -2 +3 +4 = 6 등의 수식이 나오는데 이중 첫 번 째 수식이 가장 길이가 짧고 그 때 항의 개수 3을 갖게 된다.
• 입력) 3 (→ N이 3임)
• 출력) 2 (+1 +2 = 3이 가장 길이가 짧고 항의 개수는 2)
• 입력) 6 (→ N이 6임)
• 출력) 3(+1 +2 +3 = 6이 가장 길이가 짧고 항의 개수는 3)입력) 8출력) 4

*/

#include <stdio.h>
int flag = 0;
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
			flag = 1;
		
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
	int i = 1;

	scanf("%d", &n);

	while(flag != 1 || n <= i)
	{		
		i++;
		if((i * (i + 1) / 2) < n)
			continue;
		
		pick(2, items, bucket, i, i, n);
	}

	if(i != n)
		printf("%d\n", i);
	else
		printf("NO\n");
}