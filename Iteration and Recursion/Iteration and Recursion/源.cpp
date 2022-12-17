#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;
int TIME = 3000;

struct Node {
	int data;
	struct Node* next;
};

Node* Insert(Node* head,int data);
void Iteration_Printf(Node* p);	//the value of p is local variate.
void Recurtion_Printf(Node* p);
void Reverse_Recurtion_Printf(Node* p);
void TIME_Delete();

int main() {
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);
	head = Insert(head, 7);
	Iteration_Printf(head);
	TIME_Delete();
	Recurtion_Printf(head);
	TIME_Delete();
	Reverse_Recurtion_Printf(head);
	TIME_Delete();
	Reverse_Recurtion_Printf(head);

}

Node* Insert(Node* head, int data)
{
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}

	//这个else是必须加的，想想第一节点后面怎么链接第二个节点，就明白了
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;

		}
		temp1->next = temp;
		temp->next = NULL;
	}
	return head;
}

void Iteration_Printf(Node* p)
{
	Node* temp1 = p;
	while (temp1 != NULL) {
		printf("%d ",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");

}

void Recurtion_Printf(Node* p)
{
	Node* temp2 = p;
	if (temp2 == NULL) {
		printf("\n");//换行 at the end of Recurtion.
		return;
	}
	printf("%d ",temp2->data);
	Recurtion_Printf(temp2->next);

}

void Reverse_Recurtion_Printf(Node* p)
{
	Node* temp2 = p;
	if (temp2 == NULL) {
		//printf("\n");//换行 at the end of Recurtion.
		return;
	}
	Reverse_Recurtion_Printf(temp2->next);
	printf("%d ", temp2->data);
}

void TIME_Delete()
{
	Sleep(TIME);
	if (TIME > 1000) {
		TIME = TIME - 1000;
	}
}
