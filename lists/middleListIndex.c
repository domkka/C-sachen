#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct IntList
{
    int data;
    struct IntList *next;
} IntList;

IntList *newNode(int data)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->next = malloc(sizeof(IntList));
    return node;
}

void push(IntList **head, int data){
	IntList *temp = newNode(data);
    temp->next = (*head);
    (*head) = temp;
}

void printList(IntList *head){
	IntList *temp = head;
	while(temp != NULL){
		printf("%d,", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int getListSize(IntList *head){
	IntList *temp = head;
	int result = 0;
	while(temp != NULL){
		result++;
		temp = temp->next;
	}
	return result;
}

int getMidIndexData(IntList *head){
	int result = 0;
	IntList *temp = head;
	int listSize = getListSize(head);
	if(listSize % 2 == 0){
		return result;
	}else{
		for(int i = 0; i < (listSize / 2) + 1; i++){
			result = temp->data;
			temp = temp->next;
		}
	}
	return result;
}

int main(){
	IntList *head = NULL;
	int maxAmount = 11;
	int upperLimit = 20;
	for (int i = 0; i < maxAmount; i++){
		push(&head, rand() % upperLimit);
	}
	printList(head);
	printf("%d\n", getMidIndexData(head));
}
