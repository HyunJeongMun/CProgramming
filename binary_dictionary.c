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

// ���� e1 < e2 �̸� -1 ��ȯ
// ���� e1 == e2 �̸� 0 ��ȯ
// ���� e1 > e2 �̸� 1 ��ȯ
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode * p)
{
	if (p != NULL) {

		display(p->left);
		printf("%s:%s\n", p->key.word, p->key.meaning);
		display(p->right);
	}
}
// ���� Ž�� Ʈ�� Ž�� �Լ�
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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (compare(key, node->key)<0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key)>0)
		node->right = insert_node(node->right, key);
	// ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

TreeNode *replaceMeaning(TreeNode *root, char *word, char *meaning)
{
	// �ڵ� �ۼ�
    element k;
    strcpy(k.word, word);
    strcpy(k.meaning, meaning);

	if (search(root, k) == NULL) {
		insert_node(root, k);
		printf("�������� �ʽ��ϴ�. �ܾ �߰��մϴ�.\n");
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
	printf("\n**** i : ����, s : Ž��, p : ���, r : ����, q : ���� **** :   "); 
}

// ���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷� 
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
		getchar();		// ����Ű ����: ���۸� ���� ȿ��
		switch (command) {
		case 'i':
			printf("�ܾ�:"); 
			gets(e.word);
			printf("�ǹ�:");
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'p':
			display(root);
			break;
		case 's':
			printf("�ܾ�:"); 
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL) {
				printf("�ǹ�:");
				printf("%s\n", e.meaning);
			}
			break;
		case 'r':
			printf("�ܾ�:");
			gets(word);
			printf("�ǹ�:");
			gets(meaning);
			root = replaceMeaning(root, word, meaning);
			break;
		}
	
	} while (command != 'q');
	return 0;
}