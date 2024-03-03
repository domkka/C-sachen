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

void intToBinary(int input){
	
	IntList *head = NULL;
	if(input == 0){
		push(&head, 0);
	}
	while(input != 0){
		push(&head, input % 2);
		input /= 2;
	}
	printList(head);
}

int main(){
	int test = 123;
	int test2 = 0;
	int test3 = 12;
	
	intToBinary(test);
	intToBinary(test2);
	intToBinary(test3);
	
}