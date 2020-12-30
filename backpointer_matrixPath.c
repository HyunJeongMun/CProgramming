//Memoization O - matrix path --- Backpointer
#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLS 4
#define START 1
#define LEFT 2
#define UP 3
int M[ROWS][COLS] = {
        {6,7,12,5},
        {5,3,11,18},
        {7,17,3,3},
        {8,10,14,9}
};
int min_value(int a, int b)
{
        if ( a < b ) return a;
        else return b;
}
void print_path(int i, int j , int **BP)
{
    if ( BP[i][j] == UP )
        print_path(i-1, j, BP);
    else if ( BP[i][j] == LEFT )
        print_path(i, j-1, BP);
    printf("<%d,%d> " , i, j);
}
int mat(int i, int j, int **F, int **BP)
{
        if ( F[i][j] != 0 ) return F[i][j];
        if ( i == 0 && j == 0 )
        {
                BP[i][j] = START;
                return M[i][j];
        }
        else if (i == 0)
        {
                BP[i][j] = LEFT;
                F[i][j] = mat(0, j-1, F, BP) + M[i][j];
        }
        else if (j == 0)
        {
                BP[i][j] = UP;
                F[i][j] = mat(i-1, j, F, BP) + M[i][j];
        }
        else
        {
                int a,b;
                a = mat(i-1, j,F, BP);
                b = mat(i, j-1,F, BP);
                BP[i][j] = (a<b)? UP:LEFT;
                F[i][j] = min_value(a,b) + M[i][j];
        }
        return F[i][j];
}
int main()
{
        int i,j;
        int **F, **BP;
        F = (int**) malloc( sizeof(int*) * ROWS );
        BP = (int**) malloc( sizeof(int*) * ROWS );
        for(i=0; i < ROWS; i++ ) {
                F[i] = (int*) malloc(sizeof(int) * COLS );
                BP[i] = (int*) malloc(sizeof(int) * COLS );
        }
        for(i=0; i < ROWS; i++ )
                for(j=0; j < COLS; j++ ) {
                        F[i][j] = 0;
                        BP[i][j] = 0;
                }
        printf("%d\n", mat(3,3,F,BP) );
        for(i=0; i < ROWS; i++ )
        {
                for(j=0; j < COLS; j++ )
                        printf("%d " , BP[i][j]);
                printf("\n");
        }
        print_path( 3,3, BP );
}