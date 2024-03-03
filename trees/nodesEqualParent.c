#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int data)
{
    TreeNode *new = malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}

TreeNode *createRandomTree(int treeEntries[], TreeNode *node, int index, int arrayLength)
{
    TreeNode *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}

void inOrderPrint(TreeNode *head)
{
    if (head != NULL)
    {
        inOrderPrint(head->left);
        printf("%d,", head->data);
        inOrderPrint(head->right);
    }
}

int equalNodes(TreeNode *head){
	int result = 0;
	if(head != NULL){
		if(head->left != NULL){
			if(head->data == head->left->data){
				result++;
			}
			result += equalNodes(head->left);
		}
		if(head->right != NULL){
			if(head->data == head->right->data){
				result++;
			}
			result += equalNodes(head->right);
		}
	}
	return result;
}

int main(){
	TreeNode *root = newNode(0);
    int upperLimit = 18;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % (upperLimit);
        entries[i] = randomEntry;
    }
    root = createRandomTree(entries, root, 0, upperLimit);
    inOrderPrint(root);
    printf("\n");
    printf("%d\n", equalNodes(root));
}