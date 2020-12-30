#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 100 
#define MAX_QUEUE_SIZE 100
#define INF 1000000/* 무한대(연결이없는경우) */

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;

} GraphNode;

typedef struct GraphType {
	int n; // 정점의 개수
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
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}

	(g -> n)++;
}

void insert_edge(GraphType *g, int u, int v){

	GraphNode *node;

	if (u >= g->n || v >= g->n){
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node -> vertex = v;
	node ->link = g -> adj_list[u];

	g -> adj_list[u] = node;
}

// 위상정렬을수행한다. 
int topo_sort(GraphType* g){ 
	int i, w, u; 
	QueueType q; 
	GraphNode *node;
	int *in_degree = (int*)malloc(g->n * sizeof(int)); // 모든 정점의 진입차수를 계산 

	for(i = 0; i < g -> n; i++)// 초기화 
		in_degree[i] = 0; 
	
	for(i = 0; i < g -> n; i++) { 
		node = g -> adj_list[i];//정점i에서 나오는 간선들 
		
		while(node != NULL) { 
			in_degree[node -> vertex]++; 
			node = node -> link; 
		} 
	}
	
	// 진입차수가 0인 정점을 스택에 삽입 
	init(&q); 
	for(i = 0; i < g->n; i++){ 
		if (in_degree[i] == 0) 
			enqueue(&q, i); 
	} // 위상순서를생성 
	
	while (!is_empty(&q)){ 
		w = dequeue(&q); 
		printf(" 정점 %d ->", w); //정점출력 
		
		node = g -> adj_list[w]; //각정점의진입차수를변경 
		
		while (node != NULL) { 
			u = node -> vertex; 
			in_degree[u]--; //진입차수를 감소

			if (in_degree[u] == 0) 
				enqueue(&q, u); 
			
			node = node->link; // 다음정점
		}

	} 
	
	free(in_degree); 
	printf("\n"); 
	
	return (i == g -> n); // 반환값이1이면성공, 0이면실패

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

	//정점0의인접리스트생성 
	
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3); 
	
	//정점1의인접리스트생성 
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4); 
	
	//정점2의인접리스트생성 
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5); 
	
	//정점3의인접리스트생성 
	insert_edge(&g, 3, 5);
	
	//정점4의인접리스트생성 
	insert_edge(&g, 4, 5); 
	
	//위상정렬 
	topo_sort(&g);
}

void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}

// 초기화 함수
void init(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType *q, int item)
{ 
  	if( is_full(q) ) 
		error("큐가 포화상태입니다");
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// 삭제 함수
int dequeue(QueueType *q) 
{ 
   	if( is_empty(q) )
		error("큐가 공백상태입니다");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
} 

// 보기 함수
int peek(QueueType *q) 
{ 
   	if( is_empty(q) )
		error("큐가 공백상태입니다");
	return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
} 