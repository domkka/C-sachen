#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

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

int result = 0;
int sumWithoutLeafs(IntTree *root)
{
    int sum = 0;
    while (root)
    {
        sum += sumWithoutLeafs(root->left);
        if (root->right == NULL && root->left == NULL)
        {
            return sum += root->data;
        }
        root = root->right;
    }
    return 0;
}

int main()
{
    IntTree *root = newNode(0);
    int upperLimit = 5;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % (upperLimit) + 1;
        entries[i] = randomEntry;
    }
    root = createRandomTree(entries, root, 0, upperLimit);
    inOrderPrint(root);
    printf("\n");
    printf("%d\n", sumWithoutLeafs(root));
}