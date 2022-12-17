#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void Insert(int data);
void Reverse(Node* p);
void Printf();

int main() {
	//Node* head = NULL; 为什么我在这里加个 head = NULL; Reverse中的判断就报错？？ 但在head声明全局变量时，让head = NULL;就可以编译通过; 

	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Insert(6);
	Printf();
	Node* temp3 = head;
	Reverse(temp3);
	Printf();
}

void Insert(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		Node* temp1 = head;
		while(temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = NULL;
	}
}

void Reverse(Node* p)
{   
	if (p->next == NULL) {
		head = p;
		return;
	}
	Reverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
	//p->next->next = p;

}

void Printf()
{
	Node* temp2 = head;
	while(temp2 != NULL) {
		printf("%d ",temp2->data);
		temp2 = temp2->next;
	}
	printf("\n");
}
