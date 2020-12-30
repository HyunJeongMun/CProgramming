#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 100 
#define MAX_QUEUE_SIZE 100
#define INF 1000000/* ���Ѵ�(�����̾��°��) */

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;

} GraphNode;

typedef struct GraphType {
	int n; // ������ ����
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

typedef struct {
	int  queue[MAX_QUEUE_SIZE]; 
	int  front, rear;
} QueueType; 

void error(char *message);
void init(QueueType *q);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, int item);
int dequeue(QueueType *q);
int peek(QueueType *q);

void graph_init(GraphType *g){
	int v;

	g -> n = 0;
	for(v = 0; v < MAX_VERTICES; v++)
		g -> adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v){ 
	 
	if(((g->n) + 1) > MAX_VERTICES){
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}

	(g -> n)++;
}

void insert_edge(GraphType *g, int u, int v){

	GraphNode *node;

	if (u >= g->n || v >= g->n){
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node -> vertex = v;
	node ->link = g -> adj_list[u];

	g -> adj_list[u] = node;
}

// ���������������Ѵ�. 
int topo_sort(GraphType* g){ 
	int i, w, u; 
	QueueType q; 
	GraphNode *node;
	int *in_degree = (int*)malloc(g->n * sizeof(int)); // ��� ������ ���������� ��� 

	for(i = 0; i < g -> n; i++)// �ʱ�ȭ 
		in_degree[i] = 0; 
	
	for(i = 0; i < g -> n; i++) { 
		node = g -> adj_list[i];//����i���� ������ ������ 
		
		while(node != NULL) { 
			in_degree[node -> vertex]++; 
			node = node -> link; 
		} 
	}
	
	// ���������� 0�� ������ ���ÿ� ���� 
	init(&q); 
	for(i = 0; i < g->n; i++){ 
		if (in_degree[i] == 0) 
			enqueue(&q, i); 
	} // ������������� 
	
	while (!is_empty(&q)){ 
		w = dequeue(&q); 
		printf(" ���� %d ->", w); //������� 
		
		node = g -> adj_list[w]; //���������������������� 
		
		while (node != NULL) { 
			u = node -> vertex; 
			in_degree[u]--; //���������� ����

			if (in_degree[u] == 0) 
				enqueue(&q, u); 
			
			node = node->link; // ��������
		}

	} 
	
	free(in_degree); 
	printf("\n"); 
	
	return (i == g -> n); // ��ȯ����1�̸鼺��, 0�̸����

}

int main(void) { 
	
	GraphType g;
	
	graph_init(&g); 
	insert_vertex(&g, 0);
	insert_vertex(&g, 1); 
	insert_vertex(&g, 2);
	insert_vertex(&g, 3); 
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	//����0����������Ʈ���� 
	
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3); 
	
	//����1����������Ʈ���� 
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4); 
	
	//����2����������Ʈ���� 
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5); 
	
	//����3����������Ʈ���� 
	insert_edge(&g, 3, 5);
	
	//����4����������Ʈ���� 
	insert_edge(&g, 4, 5); 
	
	//�������� 
	topo_sort(&g);
}

void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}

// �ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType *q, int item)
{ 
  	if( is_full(q) ) 
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// ���� �Լ�
int dequeue(QueueType *q) 
{ 
   	if( is_empty(q) )
		error("ť�� ��������Դϴ�");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
} 

// ���� �Լ�
int peek(QueueType *q) 
{ 
   	if( is_empty(q) )
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
} 