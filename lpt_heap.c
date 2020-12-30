#include<stdio.h> 
#include<stdlib.h>
#define MAX_ELEMENT 200 
#define JOBS 7 
#define MACHINES 3

typedef struct{ 
	int avail; 
	int id;
}element; 

typedef struct{ 
	element heap[MAX_ELEMENT]; 
	int heap_size; 
}HeapType;

//생성함수 
HeapType *create(){ 
	return(HeapType*)malloc(sizeof(HeapType)); 
}

//초기화함수 
void init(HeapType *h) { 
	h -> heap_size = 0; 
}

void insert_min_heap(HeapType *h, element item){
  int i;
  i = ++(h -> heap_size); // 힙 크기를 하나 증가

  while((i != 1) && (item.avail < h -> heap[i/2].avail)){
    h -> heap[i] = h -> heap[i/2];
    i /= 2;
  }

  h -> heap[i] = item; // 새로운 노드를 삽입
}

element delete_min_heap(HeapType *h){
  int parent, child;
  element item, temp;

  item = h->heap[1]; 
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;

  while(child <= h -> heap_size){
    if( (child < h -> heap_size) && ((h -> heap[child].avail) > h -> heap[child + 1].avail) ){
      child++;
    }
   
	if(temp.avail < h -> heap[child].avail)	break;

    h -> heap[parent] = h -> heap[child];
    parent = child;
    child *= 2;
  }
  
  h -> heap[parent] = temp;
  
  return item;
}

int main(void) { 
	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 };// 작업은 정렬되어있다고 가정 
	int i;
	element m = {0, 0}; 
	HeapType* h; 
	h = create(); 
	init(h);

	// 여기서avail 값은기계가사용가능하게되는시간이다. 
	for(i= 0; i< MACHINES; i++) { 
		m.id = i+ 1; 
		m.avail= 0; 
		insert_min_heap(h, m); 
	} 
	
	// 최소히프에서 기계를 꺼내서 작업을 할당하고 사용가능시간을 증가 시킨후에 다시 최소히프에 추가한다. 
	for (i= 0; i< JOBS; i++) { 
		m = delete_min_heap(h); 
		printf("JOB %d을 시간 = %d부터 시간 = %d까지 기계 %d번에 할당한다. \n", i, m.avail, m.avail+ jobs[i] -1, m.id); 
		m.avail+= jobs[i]; 
		insert_min_heap(h, m); 
	} 
	
}