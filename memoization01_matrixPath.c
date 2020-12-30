//Memoization O - matrix path
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int matrixPath(int **p, int i, int j, int **M) 
{
	if(i == 0 && j == 0)
		return p[i][j];
	else if(i == 0 && j > 0)
	{
		if(M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(p, i, j - 1, M);

		return p[i][j] + M[i][j - 1];
	}
	else if(i > 0 && j == 0)
	{
		if(M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(p, i - 1, j, M);

		return p[i][j] + M[i - 1][j];
	}
	else
	{
		if(M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(p, i, j - 1, M);

		if(M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(p, i - 1, j, M);

		if(M[i - 1][j] < M[i][j - 1])
			return p[i][j] + M[i - 1][j];
		else
			return p[i][j] + M[i][j - 1];
	}
}

int main(void)
{
	int row, col, i, j;
	int **p, **M;
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

	M = (int**)malloc(sizeof(int*) * row);
	for(i = 0; i < row; i++) 
		M[i] = (int*)malloc(sizeof(int) * col);

	for(i = 0; i < row; i++) 
		for(j = 0; j < col; j++ )
			M[i][j] = 0;

	min = matrixPath(p, row - 1, col - 1, M);
	printf("최소경로 = %d\n", min);

	for(i = 0; i < row; i++)
		free(p[i]);
	free(p);

	for(i = 0; i < row; i++)
		free(M[i]);
	free(M);
}