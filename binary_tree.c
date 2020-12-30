// 이진트리에 관해
#include <stdio.h> 
#include <stdlib.h> 
#include <memory.h> 
#define TRUE 1 
#define FALSE 0 
#define MAX_TREE_SIZE 20 

typedef struct TreeNode {  
	int data;  
	struct TreeNode *left, *right; 
} TreeNode; 

TreeNode *root = NULL;

TreeNode* insert(TreeNode *r, int data){

	if(r == NULL){
		r = (TreeNode*)malloc(sizeof(TreeNode));
		r -> left = r -> right = NULL;
		r -> data = data;
	}
	else{
		if(r -> data > data)
			r -> left = insert(r -> left, data);
		else
			r -> right = insert(r -> right, data);
	}
	
	return r;
}
TreeNode* delete_node(TreeNode *r, int key){
	TreeNode *temp;

	if (r == NULL) return r;
	
	if (key < r -> data)
		r -> left = delete_node(r -> left, key); 
	else if (key > r -> data)
		r -> right = delete_node(r -> right, key);
	else{
		// 첫번째나 두번째 경우 
		if (r -> left == NULL) { 
			temp = r -> right; 
			free(r);
			return temp;
		} 
		else if (r -> right == NULL) { 
			temp = r -> left; 
			free(r); 
			return temp;
		}
		else{
			temp = r;
			
			while(temp -> left != NULL)
				temp = temp -> left;

			// 중외순회시후계노드를복사한다. 
			r -> data = temp -> data; 
			// 중외순회시후계노드를삭제한다. 
			r -> right = delete_node(r -> right, temp -> data);
		}
	}

	return r;
}

int get_nonleaf_count(TreeNode *r){
	//이진 트리에서 비단말노드의 개수를 계산하는 함수를 작성해보자. 단말노드의 개수를 계산하는 교재의 <알고리즘 7.7>을 참조한다.

	if(r != NULL){
		if(r -> left != NULL ||  r -> right != NULL)
			return 1 + get_nonleaf_count(r -> right) + get_nonleaf_count(r -> left);
		else
			return get_nonleaf_count(r -> right) + get_nonleaf_count(r -> left);
	}
	else
		return 0;

}
int get_oneleaf_count(TreeNode *r){ 
	//이진 트리에서 자식이 하나인 노드의 개수를 반환

	if(!r)	return 0;
	else if((r -> left != NULL &&  r -> right == NULL) || ((r -> left == NULL &&  r -> right != NULL)))
			return 1 + get_oneleaf_count(r -> right) + get_oneleaf_count(r -> left);
	else
		return get_oneleaf_count(r -> right) + get_oneleaf_count(r -> left);
}

int get_twoleaf_count(TreeNode *r) {
	//이진 트리에서 자식이 둘인 노드의 개수를 반환

	if(r == NULL)	return 0;
	else if(r -> left != NULL &&  r -> right != NULL)
			return 1 + get_twoleaf_count(r -> right) + get_twoleaf_count(r -> left);
	else
		return get_twoleaf_count(r -> right) + get_twoleaf_count(r -> left);
}

int get_max(TreeNode *r){
	//이진 트리에서 노드값들 중 최대값을 반환
	
	while(r -> right != NULL)
		r = r -> right;

	return r -> data;
}

int get_min (TreeNode *r){
	//이진 트리에서 노드값들 중 최소값을 반환

	while(r -> left != NULL)
		r = r -> left;

	return r -> data;
}

TreeNode* search(TreeNode *root, int key){
	//이진 트리에서 주어진 key 값을 갖는 노드를 반환

	if(root == NULL) return NULL;
	else {
		if(root -> data == key)
			return root;

		if(root -> data > key)
			search(root -> left, key);
		else
			search(root -> right, key);
	}
}


void inorder(TreeNode *root) {      
	if(root) {                   
		inorder(root->left);
		printf("%d ", root->data);  
		inorder(root->right);      
	} 
} 

int main(void) {
	TreeNode *node;
	int min, max;

	root = insert(root, 15);
	root = insert(root, 4);
	root = insert(root, 16);
	root = insert(root, 28);
	root = insert(root, 25);
	root = insert(root, 17);
	root = insert(root, 19);

	inorder(root);    
	printf("\n"); 

	node = search(root, 17);
	if(node != NULL)
		printf("%d\n", node -> data);
	else
		printf("It is not exist\n");

	max = get_max(root);
	min = get_min(root);
	printf("Max : %d, Min : %d\n", max, min);

	delete_node(root, node -> data);
	inorder(root);    
	printf("\n"); 
} 
