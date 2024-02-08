#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct IntList
{
    int data;
    int price;
    struct IntList *next;
} IntList;

IntList *newNode(int data, int price)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->price = price;
    node->next = malloc(sizeof(IntList));
    return node;
}

void push(IntList **head, int data, int price)
{
    IntList *new = newNode(data, price);
    new->next = (*head);
    (*head) = new;
}

void printList(IntList *head)
{
    if (head == NULL)
    {
        printf("nothing to print, since list is empty\n");
    }
    IntList *current = head;
    int i = 1;
    while (current != NULL)
    {
        printf("%d.weight %d, price: %d\n", i, current->data, current->price);
        current = current->next;
        i++;
    }
}

int sumListPrice(IntList *head){
	int sum = 0;
	IntList *temp = head;
	while(temp != NULL){
		sum += temp->price;
		temp = temp->next;
	}
	return sum;
}

int minMaxWeight(IntList *head){
	IntList *temp = head;
	int maxPrice = 0;
	int amount = 0;
	while(maxPrice < ((sumListPrice(head) / 2) + 1) && temp != NULL){
		maxPrice += temp->price;
		amount++;
	}
	printf("elementCount = %d: ", amount);
	return maxPrice;
	
}

void swap(IntList *a, IntList *b){
	int temp = a->price;
	a->price = b->price;
	b->price = temp;
}

int getListSize(IntList *head)
{
    int listSize = 0;
    IntList *copy = head;
    while (copy != NULL)
    {
        listSize++;
        copy = copy->next;
    }
    return listSize;
}

void bubbleSort(IntList *head){
	int size = getListSize(head);
	IntList *temp = head;
	
	if(head == NULL){
		return;
	}
	for(int i = 0; i < size; i++){
		temp = head;
		while(temp->next != NULL){
			if(temp->price < temp->next->price){
				swap(temp, temp->next);
			}
			temp = temp->next;
		}
	}
	
}

int main()
{
    IntList *head = NULL;
    int maxAmount = 10;
    int upperWeightLimit = 50;
    int upperPriceLimit = 200;
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        push(&head, rand() % upperWeightLimit, rand() % upperPriceLimit);
    }
    printList(head);
    printf("\n");
    printf("list sum: %d€\n", sumListPrice(head));
    bubbleSort(head);
    printList(head);
    printf("sum: %d\n", minMaxWeight(head));
}