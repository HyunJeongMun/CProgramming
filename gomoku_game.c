#include <stdio.h>
#define BOARD_SIZE 10

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
	char player = b[r][c];
	int count = 1;
	int i, j;

	i = c + 1;
	while(b[r][i] == player && i < BOARD_SIZE && count <= 5) //Right
	{
		count++;
		i++;
	}

	i = c - 1;
	while(b[r][i] == player && i >= 0 && count <= 5) //Left
	{
		count++;
		i--;
	}

	if(count == 5)
		return 1;
	else
		count = 1;
	// 수평

	i = r - 1;
	while(b[i][c] == player && i >= 0 && count <= 5) //Up
	{
		count++;
		i--;
	}

	i = r + 1;
	while(b[i][c] == player && i < BOARD_SIZE && count <= 5) //Down
	{
		count++;
		i++;
	}

	if(count == 5)
		return 1;
	else
		count = 1;
	//수직

	i = r - 1;
	j = c - 1;
	while(b[i][j] == player && i >= 0 && j >= 0 && count <= 5) //Up
	{
		count++;
		i--;
		j--;
	}

	i = r + 1;
	j = c + 1;
	while(b[i][j] == player && i < BOARD_SIZE && j < BOARD_SIZE && count <= 5) //Down
	{
		count++;
		i++;
		j++;
	}

	if(count == 5)
		return 1;
	else
		count = 1;
	//오른쪽대각선

	i = r - 1;
	j = c + 1;
	while(b[i][j] == player && i >= 0 && j < BOARD_SIZE && count <= 5) //Up
	{
		count++;
		i--;
		j++;
	}

	i = r + 1;
	j = c - 1;
	while(b[i][c] == player && j >= 0 && i < BOARD_SIZE && count <= 5) //Down
	{
		count++;
		i++;
		j--;
	}

	if(count == 5)
		return 1;
	else
		return 0;
	//왼쪽 대각선
}

void display(char b[][BOARD_SIZE])
{
	char ch;
	int i, j;

	printf("     ");
	for(i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);

	printf("\n     ---------------------     \n");
	for(i = 0; i < BOARD_SIZE; i++)
	{
		printf("%3d |", i);

		for(j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]);
		
		printf("\n");
	}
}

int main(void)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';
	int r, c;
	int i, j;
	int count;
	int winner;

	for(i = 0; i < BOARD_SIZE; i++)
		for(j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';

	count = 1;

	display(board);

	do
	{
		printf("Player %c(행, 열):", turn);
		scanf("%d %d", &r, &c);

		if(board[r][c] != ' ')
			continue;

		board[r][c] = turn;
		display(board);

		if(winner = winCheck(board, r, c))
			printf("Player %c wins!\n", turn);

		turn = (turn == 'X'? 'O':'X');
		count++;
	}
	while(!winner && count <= BOARD_SIZE * BOARD_SIZE);

	if(!winner && count <= BOARD_SIZE * BOARD_SIZE)
		printf("Nobody win!\n");
}