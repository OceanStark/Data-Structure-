#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head = NULL;
void Insert(int data);
void Printf();
void Reverse();

int main() {
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Printf();
	Reverse();
	Printf();
}

void Insert(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}

void Printf(){
	Node* temp1 = head;
	while (temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}

void Reverse(){
	stack<struct Node*> Sstack;
	Node* temp2 = head;
	while (temp2 != NULL) {
		Sstack.push(temp2);
		temp2 = temp2->next;
	}
	temp2 = head = Sstack.top();
	Sstack.pop();
	while (!Sstack.empty()) {
		temp2->next = Sstack.top();
		temp2 = temp2->next;
		Sstack.pop();
	}
	temp2->next = NULL;
}
