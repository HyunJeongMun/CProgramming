#include<stdio.h>
#define X_VALUE 5 //2차원 배열의 행의 수
#define Y_VALUE 5 //2차원 배열의 열의 수

void readBombInfo(char grid[][Y_VALUE+1]) // grid 및 지뢰 정보 입력
{
	int i;

	printf("Input Grid\n");

	for(i = 0 ; i < X_VALUE; i++ )
		scanf( "%s", grid[i] );
}

void countBomb(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE]) // 지뢰의 개수를 세어 numOfBombs에 넣는 코드 작성
{
	int i, j;
 
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
		{
			if (grid[i][j] == '*')
			{
				if(i == 0)
				{
					if(j == 0)
					{
						numOfBombs[i + 1][j]++;
						numOfBombs[i][j + 1]++;
						numOfBombs[i + 1][j + 1]++;
					}
					else if(j == 4)
					{
						numOfBombs[i][j - 1]++;
						numOfBombs[i + 1][j]++;
						numOfBombs[i + 1][j - 1]++;
					}
					else
					{
						numOfBombs[i][j - 1]++;
						numOfBombs[i][j + 1]++;
						numOfBombs[i + 1][j - 1]++;
						numOfBombs[i + 1][j]++;
						numOfBombs[i + 1][j + 1]++;
					}
				}
				else if(i == 4)
				{
					if(j == 0)
					{
						numOfBombs[i - 1][j]++;
						numOfBombs[i][j + 1]++;
						numOfBombs[i - 1][j + 1]++;
					}
					else if(j == 4)
					{
						numOfBombs[i][j - 1]++;
						numOfBombs[i - 1][j]++;
						numOfBombs[i - 1][j - 1]++;
					}
					else
					{
						numOfBombs[i][j - 1]++;
						numOfBombs[i][j + 1]++;
						numOfBombs[i - 1][j - 1]++;
						numOfBombs[i - 1][j]++;
						numOfBombs[i - 1][j + 1]++;
					}
				}
				else
				{
					if(j == 0)
					{
						numOfBombs[i + 1][j]++;
						numOfBombs[i + 1][j + 1]++;
						numOfBombs[i][j + 1]++;
						numOfBombs[i - 1][j]++;
						numOfBombs[i - 1][j + 1]++;
					}
					else if(j == 4)
					{
						numOfBombs[i + 1][j - 1]++;
						numOfBombs[i + 1][j]++;
						numOfBombs[i][j -1]++;
						numOfBombs[i - 1][j - 1]++;
						numOfBombs[i - 1][j]++;
					}
					else
					{
						numOfBombs[i + 1][j - 1]++;
						numOfBombs[i + 1][j]++;
						numOfBombs[i + 1][j + 1]++;
						numOfBombs[i][j -1]++;
						numOfBombs[i][j + 1]++;
						numOfBombs[i - 1][j - 1]++;
						numOfBombs[i - 1][j]++;
						numOfBombs[i - 1][j + 1]++;
					}
				}
			}
		}

}

void display_numOfBombs(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE])
{
	int i, j;
 
	for (i = 0; i < X_VALUE; i++) 
	{
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);

		printf("\n");
	}
}

int main(void)
{
	char grid[X_VALUE][Y_VALUE+1]; //문자열의 경우 마지막에 NULL이 들어가야 하므로 5X5 배열이 아닌 5X6 배열이 되어야 한다.
	int numOfBombs[X_VALUE][Y_VALUE] = {0}; //지뢰의 개수를 넣는 정수형 5X5 배열

	readBombInfo(grid);

	countBomb(grid, numOfBombs);

	display_numOfBombs(grid, numOfBombs);
}	