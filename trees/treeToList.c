#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct IntNode{
	int data;
	struct IntNode *next;
}IntNode;

IntNode *newNodeList(int data){
	IntNode *temp = malloc(sizeof(IntNode));
	temp->data = data;
	temp->next = NULL;
}

typedef struct IntTree
{
    int data;
    struct IntTree *left;
    struct IntTree *right;
} IntTree;

IntTree *newNode(int data)
{
    IntTree *temp = malloc(sizeof(IntTree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

void inOrderPrint(IntTree *head)
{
    if (head != NULL)
    {
        inOrderPrint(head->left);
        printf("%d,", head->data);
        inOrderPrint(head->right);
    }
}

IntTree *createRandomTree(int treeEntries[], IntTree *node, int index, int arrayLength)
{
    IntTree *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}

IntNode *treeToList(IntTree *head, int limit){
	
	if(head == NULL){
		return NULL;
	}
	
	IntNode *l1 = treeToList(head->left, limit);
	IntNode *l2 = treeToList(head->right, limit);
	
	if(head->data < limit){
		IntNode *newNode = newNodeList(head->data);
		l1->next = newNode;
		l1 = newNode;
	}else{
		IntNode *newNode = newNodeList(head->data);
		l2->next = newNode;
		l2 = newNode;
	}
	
	
	IntNode * temp = l1;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = l2;
	
	return l1;
}

int main(){
	IntTree *root = newNode(0);
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
	//preOrderPrint(root);
	printf("\n");
	
	IntNode *list = treeToList(root, 2);
	IntNode *temp = list;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
    inOrderPrint(root);
    printf("\n");
}