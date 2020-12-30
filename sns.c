#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_OF_MEMBERS 5

void print_links(int data[][NUM_OF_MEMBERS] ); //2���� �迭 ���
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS] );//2���� �迭 ���� data X data = result

int main( void )
{

	// 0�� 1, 1�� 2, 2�� 4, 3�� 4�� ���� 1������ ���̵��� �迭�� �ʱ�ȭ�϶�.
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {{1, 1, 0, 0, 0}, {1, 1, 1, 0, 0}, {0, 1, 1, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 1, 1, 1}};

	 // 2�� ���踦 ���� �迭�� 0���� �ʱ�ȭ�Ѵ�.
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};

	printf("=================================================================\n");
	printf("Friends matrix\n");
	printf("=================================================================\n");

	print_links(link_data); // ���� 1�� ���� ���


	matrix_multiplication(link_data, link_result); // 2�� ���踦 link_result�� �ִ´�

	printf("=================================================================\n");
	printf("Friends of friends matrix\n");
	printf("=================================================================\n");

	print_links(link_result); // 2�̱����� ���� ���

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
