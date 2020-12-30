#include <stdio.h> 
#include <stdlib.h>
#define TRUE 1 
#define FALSE 0
#define MAX_VERTICES 100 
#define INF 1000
int parent[MAX_VERTICES];// 부모노드

// 초기화
void set_init(int n){ 
	int i;
	
	for(i = 0; i < n; i++) 
		parent[i] = -1; 
} 

// curr가속하는집합을반환한다. 
int set_find(int curr) { 
	if(parent[curr] == -1) 
		return curr; 
	
	// 루트 
	while (parent[curr] != -1) 
		curr= parent[curr]; 
	
	return curr; 
}

// 두개의원소가속한집합을합친다. 
void set_union(int a, int b) { 
	int root1 = set_find(a);// 노드a의루트를찾는다. 
	int root2 = set_find(b);// 노드b의루트를찾는다. 
	
	if (root1 != root2) // 합한다. 
		parent[root1] = root2; 
}

struct Edge {
	// 간선을나타내는구조체 
	int start, end, weight; 
};

typedef struct GraphType{ 
	int n;// 간선의개수 
	struct Edge edges[2 * MAX_VERTICES]; 
} GraphType;

// 그래프초기화 
void graph_init(GraphType* g) {
	int i;

	g -> n = 0; 

	for(i = 0; i < 2 * MAX_VERTICES; i++) { 
		g -> edges[i].start = 0; 
		g -> edges[i].end = 0; 
		g -> edges[i].weight = INF; 
	} 
} 

// 간선삽입연산 
void insert_edge(GraphType* g, int start, int end, int w) { 

	g -> edges[g -> n].start = start; 
	g -> edges[g -> n].end = end; 
	g -> edges[g -> n].weight = w; 
	g -> n++; 

} 

// qsort()에사용되는함수 
int compare(const void* a, const void* b) { 
	struct Edge *x = (struct Edge*)a; 
	struct Edge *y = (struct Edge*)b; 
	
	return (x -> weight - y -> weight); 
}

// kruskal의최소비용신장트리프로그램 
void kruskal(GraphType *g) { 
	int edge_accepted= 0;// 현재까지선택된간선의수 
	int uset, vset;// 정점u와정점v의집합번호 
	struct Edge e;
	int i = 0;

	set_init(g -> n);// 집합초기화 
	qsort(g -> edges, g -> n, sizeof(struct Edge), compare);

	printf("크루스칼최소신장트리알고리즘\n"); 
	
	while (edge_accepted < (g -> n -1))// 간선의수< (n-1) 
	{ 
		e = g -> edges[i]; 
		uset= set_find(e.start); // 정점u의집합번호 
		vset= set_find(e.end); // 정점v의집합번호 
		
		if (uset!= vset) {// 서로속한집합이다르면 
			printf("간선(%d,%d) %d 선택\n", e.start, e.end, e.weight); 
			edge_accepted++; 
			set_union(uset, vset);// 두개의집합을합친다. 
		} 
		
		i++; 
	}
}

int main(void) { 
	GraphType *g; 
	g = (GraphType*)malloc(sizeof(GraphType)); 
	graph_init(g);

	insert_edge(g, 0, 1, 29); 
	insert_edge(g, 1, 2, 16); 
	insert_edge(g, 2, 3, 12); 
	insert_edge(g, 3, 4, 22); 
	insert_edge(g, 4, 5, 27); 
	insert_edge(g, 5, 0, 10); 
	insert_edge(g, 6, 1, 15); 
	insert_edge(g, 6, 3, 18); 
	insert_edge(g, 6, 4, 25);

	kruskal(g); 
	free(g);
}