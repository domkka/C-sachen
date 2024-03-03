#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node{
	
	int data;
	struct Node *left;
	struct Node *right;
}Node;

Node *newNode(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

void preOrderPrint(Node *root){
	if(root != NULL){
		printf("%d,", root->data);
		preOrderPrint(root->left);
		
		preOrderPrint(root->right);
	}
}

void inOrderPrint(Node *root){
	if(root != NULL){
		
		inOrderPrint(root->left);
		printf("%d,", root->data);
		inOrderPrint(root->right);
	}
}

Node *createRandomTree(int treeEntries[], Node *node, int index, int arrayLength)
{
    Node *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}

int sumRightNodes(Node *root){
	int sum = 0;
	if(root != NULL){
		sum += sumRightNodes(root->right);
		if(root->right != NULL){
			sum += root->right->data;
		}
		
	}
	
	return sum;
}

int main()
{
    Node *root = newNode(0);
    int upperLimit = 7;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % (upperLimit) + 1;
        entries[i] = randomEntry;
    }
    root = createRandomTree(entries, root, 0, upperLimit);
	preOrderPrint(root);
	printf("\n");
    inOrderPrint(root);
    printf("\n");
    printf("%d\n", sumRightNodes(root));
}