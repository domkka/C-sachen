#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node *newNode(int data){
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void push(Node **head, int data){
	Node *temp = newNode(data);
	temp->next = (*head);
	(*head) = temp;
}

void printList(Node *head){
	Node *temp = head;
	while(temp != NULL){
		printf("%d,",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int sumList(Node *head){
	Node *temp = head;
	int sum = 0;
	while(temp != NULL){
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

void reverseList(Node **head){
	Node *temp = *head;
	Node *prev = NULL;
	Node *next;
	while(temp != NULL){
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*head = prev;
}

int nodeDifference(Node *head){
	Node *temp = head;
	int min = head->data;
	int max = head->data;
	while(temp != NULL){
		if(temp->data < min){
			min = temp->data;
		}
		if(temp->data > max){
			max = temp->data;
		}
		temp = temp->next;
	}
	return max - min;
	
}

int main(){
	Node *head = NULL;
	srand(time(NULL));
	int maxAmount = 11;
	int upperLimit = 20;
	for (int i = 0; i < maxAmount; i++){
		push(&head, rand() % upperLimit);
	}
	printList(head);
	reverseList(&head);
	printList(head);
	printf("%d\n", sumList(head));
	printf("%d\n", nodeDifference(head));
}