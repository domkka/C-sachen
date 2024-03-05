#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

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

void printAsTree(IntTree *root, int space)
{
    int count = 10;

    if (root == NULL)
    {
        return;
    }

    space += count;
    printAsTree(root->right, space);

    printf("\n");

    for (int i = count; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printAsTree(root->left, space);
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

int maxValue(IntTree *root){
	
	if(root == NULL){
		return 0;
	}
	
	int res = root->data;
	int left = maxValue(root->left);
	int right = maxValue(root->right);
	
	return max(max(left,right),res);
}

int main()
{
    int upperLimit = 7;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % (upperLimit);
        entries[i] = randomEntry;
    }
    IntTree *root = newNode(0);
    root = createRandomTree(entries, root, 0, upperLimit);
    printAsTree(root, 10);
    int max = maxValue(root);
	printf("\nMax is %d", max);
	return 0;
	
}