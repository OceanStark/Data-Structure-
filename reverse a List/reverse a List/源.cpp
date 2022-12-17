#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

// struct Node* head;

struct Node* reverse(Node* head);
void Printf(Node* head);
struct Node* Insert(int data,Node* head);

Node* reverse(Node* head){
	Node* prev, * current, * next;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}
	 head = prev;
	 return head;
}

void Printf(Node* head){
	Node* temp1 = head;
	while (temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}

Node* Insert(int data,Node* head){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	Node* temp1 = head;
	while (temp1->next != NULL) {
		temp1 = temp1->next;	
	}
	temp1->next = temp;
	temp->next = NULL;
	return head;
}


int main() {
	Node* head = NULL;
	head = Insert(2,head);
	head = Insert(3, head);
	head = Insert(4, head);
	head = Insert(5, head);
	head = Insert(6, head);
	head = Insert(7, head);
	Printf(head);
	head = reverse(head);
	Printf(head);

}
