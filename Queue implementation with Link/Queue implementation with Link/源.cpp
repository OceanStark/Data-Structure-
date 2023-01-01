#include<stdio.h>
#include<iostream>
#include<stdlib.h>

struct Node{
	int data;
	Node* next;
};

Node* Front = NULL;
Node* Rear = NULL;

void Enqueue(int data);
bool IsEmpty();
void Printf();
void Dequeue();
void FrontHead();

bool IsEmpty(){
	if (Front == NULL) return true;
	else return false;
}

void Printf(){
	Node* temp = Front;
	while (temp!= NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Dequeue() {

	Node* temp = Front;
	if (IsEmpty()) {
		printf("This Queue is Empty!\n");
		return;
	}
	if (Front == Rear) Front = Rear = NULL;
	else {
		Front = Front->next;
	}
	free(temp);
}

void FrontHead(){
	printf("%d ",Front->data);
}

void Enqueue(int data) {
	//Node* temp = (struct Node*)malloc(sizeof(struct Node ));   
	

	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;

	if (IsEmpty()) {
		Front = Rear = temp;
		return;
	}

	Rear->next = temp;
	Rear = temp;

}




int main() {
	Enqueue(2);
	Enqueue(3);
	Enqueue(3);
	Printf();
	Dequeue();
	Printf();
	FrontHead();

}
