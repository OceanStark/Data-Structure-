#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;	//global
void Insert(int data);
void Printf();
void Delete(int n);


int main() {
	
	Node* head = NULL;
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Insert(6);
	Insert(7);
	Insert(8);
	Insert(9);


	Printf();
	int n;
	printf("please input random node\n");
	while (scanf_s("%d", &n) != 0) {
		Delete(n);
		Printf();
	}
}

void Insert(int data)
{	
	Node* temp = new Node();
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
		temp->next = NULL; //这句不是废话 有用的
	}

}

void Printf()
{	
	Node* temp4 = head;

	while (temp4 != NULL) {
		printf("%d ",temp4->data);
		temp4 = temp4->next;
	}
	printf("\n");
}

void Delete(int n)
{
	Node* temp2 = head;
	if (n == 1) {
		head = temp2->next;
		free(temp2);
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	Node* temp3 = temp2->next;
	temp2->next = temp3->next;
	free(temp3);
}
