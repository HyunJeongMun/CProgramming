#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 100 
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
	int stack[MAX_VERTICES];
	int top;
} StackType;

int peek(StackType *s);
int pop(StackType *s);
void push(StackType *s, int item);
int is_empty(StackType *s);
int is_full(StackType *s);
void init(StackType *s);

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
	StackType s; 
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
	init(&s); 
	for(i = 0; i < g->n; i++){ 
		if (in_degree[i] == 0) 
			push(&s, i); 
	} // 위상순서를생성 
	
	while (!is_empty(&s)){ 
		w = pop(&s); 
		printf(" 정점 %d ->", w); //정점출력 
		
		node = g -> adj_list[w]; //각정점의진입차수를변경 
		
		while (node != NULL) { 
			u = node -> vertex; 
			in_degree[u]--; //진입차수를 감소

			if (in_degree[u] == 0) 
				push(&s, u); 
			
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

// 스택 초기화 함수

void init(StackType *s){ 
	s -> top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == (MAX_VERTICES - 1));
}

// 삽입함수
void push(StackType *s, int item){

	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else 
		s->stack[++(s->top)] = item;
}

// 삭제함수
int pop(StackType *s){

	if(is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->stack[(s->top)--];

}

// 피크함수
int peek(StackType *s){

	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->stack[s->top];
}
 