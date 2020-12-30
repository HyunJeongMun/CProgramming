//Memoization X - matrix path
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int matrixPath(int **p, int i, int j) 
{
	if(i == 0 && j == 0)
		return p[i][j];
	else if(i == 0 && j > 0)
		return p[i][j] + matrixPath(p, i, j - 1);
	else if(i > 0 && j == 0)
		return p[i][j] + matrixPath(p, i - 1, j);
	else
	{
		if(matrixPath(p, i, j - 1) < matrixPath(p, i - 1, j))
			return p[i][j] + matrixPath(p, i, j - 1);
		else
			return p[i][j] + matrixPath(p, i - 1, j);
	}
}
int main(void)
{
	int row, col, i, j;
	int **p;
	int min;

	printf("Enter the row and col : ");
	scanf("%d %d", &row, &col);

	p = (int**)malloc(sizeof(int*) * row);
	for(i = 0; i < row; i++) 
		p[i] = (int*)malloc(sizeof(int) * col);

	srand(time(NULL));
	for(i = 0; i < row; i++) 
	{
		for(j = 0; j < col; j++ )
		{
			p[i][j] = rand() % 10;
			printf("%4d", p[i][j]);
		}
		printf("\n");
	}

	min = matrixPath(p, row - 1, col - 1);
	printf("최소경로 = %d\n", min);
}