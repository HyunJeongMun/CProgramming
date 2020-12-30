#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 10
#define MAX_MEANING_SIZE 20

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2 이면 0 반환
// 만약 e1 > e2 이면 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// 이진 탐색 트리 출력 함수
void display(TreeNode * p)
{
	if (p != NULL) {

		display(p->left);
		printf("%s:%s\n", p->key.word, p->key.meaning);
		display(p->right);
	}
}
// 이진 탐색 트리 탐색 함수
TreeNode * search(TreeNode * root, element key)
{
	TreeNode * p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p;
}


TreeNode * new_node(element item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode * node, element key)
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (compare(key, node->key)<0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key)>0)
		node->right = insert_node(node->right, key);
	// 루트 포인터를 반환한다. 
	return node;
}

TreeNode *replaceMeaning(TreeNode *root, char *word, char *meaning)
{
	// 코드 작성
    element k;
    strcpy(k.word, word);
    strcpy(k.meaning, meaning);

	if (search(root, k) == NULL) {
		insert_node(root, k);
		printf("존재하지 않습니다. 단어를 추가합니다.\n");
	}
	else {
		TreeNode* p = search(root, k);
		strcpy(k.meaning, meaning);
		p -> key = k;
	}
       
    
    return root;
}

TreeNode* minnode(TreeNode* p) {
	TreeNode* min = p;
	while (min->left != NULL) min = min->left;
	return min;
}

TreeNode* deletenode(TreeNode* root, element word) {
	if (root == NULL) return root;

	if (compare(word, root->key)) {
		root->left = deletenode(root->left, word);
	}
	else if (compare(word, root->key)) {
		root->right = deletenode(root->right, word);
	}
	else {

		if (root->left == NULL) {
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL) {
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}

		TreeNode* tmp = minnode(root->right);
		root->key = tmp->key;
		root->right = deletenode(root->right, tmp->key);
	}

	return root;
}

void help()
{
	printf("\n**** i : 삽입, s : 탐색, p : 출력, r : 수정, q : 종료 **** :   "); 
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
int main(void)
{
	char command;
	element e;
	TreeNode * root = NULL;
	TreeNode * tmp;
	char word[20], meaning[20];

	do {
		help();
		command = getchar();
		getchar();		// 엔터키 제거: 버퍼를 비우는 효과
		switch (command) {
		case 'i':
			printf("단어:"); 
			gets(e.word);
			printf("의미:");
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'p':
			display(root);
			break;
		case 's':
			printf("단어:"); 
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL) {
				printf("의미:");
				printf("%s\n", e.meaning);
			}
			break;
		case 'r':
			printf("단어:");
			gets(word);
			printf("의미:");
			gets(meaning);
			root = replaceMeaning(root, word, meaning);
			break;
		}
	
	} while (command != 'q');
	return 0;
}