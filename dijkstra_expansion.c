#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* ����� �� */
#define INF 	9999		/* ���� ��(������ ���� ���) */

int distance[MAX_VERTICES];	/* ���۳��κ����� �ִܰ�� �Ÿ� */
int previous[MAX_VERTICES];	/* ���� ���  */
int found[MAX_VERTICES];	/* �湮�� ��� ǥ�� */

typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
	int r,c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

     for (r = 0; r < MAX_VERTICES; r++) // pak �߰�, �ڱ��ڽſ����� �Ÿ��� 0����
          g->adj_mat[r][r] = 0;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
	int n, u, v;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) { 
		fprintf(stderr, "���� %s�� �� �� ����!\n", filename); return;  
	}
	fscanf(fp, "%d\n", &n);
	g->n = n;
	while (fscanf(fp, "%d %d", &u, &v) != EOF) {
		fscanf(fp, "%d\n", &g->adj_mat[u][v]);
		g->adj_mat[v][u] = g->adj_mat[u][v];
	}
	fclose(fp);
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && ! found[i]) {
			min = distance[i];
			minpos=i;
		}
	return minpos;
}

void print_path(int start, int end) // ���� ����� ���ְ� ����
{  
	if (start == end) 
		printf("%d", start);
	else {
		print_path(start, previous[end]);
		printf("-> %d ", end);
	}
}

void shortest_path(GraphType *g, int start, int end)
{  
	int i, u, w;
	for(i=0; i<g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->adj_mat[start][i];
		found[i] = FALSE;
        previous[i] = start;
	}

	found[start] = TRUE;    /* ���۳�� �湮 ǥ�� */
	distance[start] = 0;	
  
     while(1) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;

		if(u == end)	break;
       
		for(w = 0; w < g->n; w++) {
			if(!found[w])
				if( distance[u] + g->adj_mat[u][w] < distance[w] ) {
					distance[w] = distance[u] + g->adj_mat[u][w];	
					previous[w] = u;		/* ������� ���� */
                    }
		}
	 }

	print_path(start, u);
	printf(" (%d)\n", distance[u]);

}

void main()
{
	GraphType g;		// �Է� �׷���
	char start[50], dest[50];
     int i, sIndex, dIndex;

     graph_init(&g);
     
	read_graph(&g, "input.txt");
	
     printf("������:");
     scanf("%d", &sIndex);
	 printf("������:");
	 scanf("%d", &dIndex);
	shortest_path(&g, sIndex, dIndex);
}
