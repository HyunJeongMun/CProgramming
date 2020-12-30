#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_OF_MEMBERS 5

void print_links(int data[][NUM_OF_MEMBERS] ); //2차원 배열 출력
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS] );//2차원 배열 논리곱 data X data = result

int main( void )
{

	// 0과 1, 1과 2, 2와 4, 3과 4가 각각 1촌임을 보이도록 배열을 초기화하라.
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {{1, 1, 0, 0, 0}, {1, 1, 1, 0, 0}, {0, 1, 1, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 1, 1, 1}};

	 // 2촌 관계를 넣을 배열을 0으로 초기화한다.
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};

	printf("=================================================================\n");
	printf("Friends matrix\n");
	printf("=================================================================\n");

	print_links(link_data); // 최초 1촌 관계 출력


	matrix_multiplication(link_data, link_result); // 2촌 관계를 link_result에 넣는다

	printf("=================================================================\n");
	printf("Friends of friends matrix\n");
	printf("=================================================================\n");

	print_links(link_result); // 2촌까지의 관계 출력

}

void print_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
	{
		for(j = 0; j < NUM_OF_MEMBERS; j++)
			printf("%4d", data[i][j]);

		printf("\n");
	}
}

void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS])
{
	int num;
	int i, j, k;

	for(i = 0 ; i < NUM_OF_MEMBERS; i++)
	{
		for(j = 0; j < NUM_OF_MEMBERS; j++)
		{
			num = 0;

			for(k = 0; k < NUM_OF_MEMBERS; k++)
				num += data[i][k] * data[k][j]; 

			result[i][j] = num;
		}
	}

	for(i = 0; i < NUM_OF_MEMBERS; i++)
	{
		for(j = 0; j < NUM_OF_MEMBERS; j++)
		{
			if(i == j)
				result[i][j] = 1;
			else if(data[i][j] == 1)
				result[i][j] = 1;
		}
	}
}
