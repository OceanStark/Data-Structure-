#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* List;
};
Node* Top = NULL;

void Push(int x);
void Printf();
void Pop();

int main() {
	char state = 'N';
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
//	Push(6);
	while (state != 'Y') {
		Printf();
		printf("whether exit this Pop\n");
		printf("Y or N\n");
		Pop();
		cin >> state;
		if (state != 'Y' || state != 'N') {
			printf("input invalid commend!\n");
			return 0;
		}
	}
	Printf();
}

void Push(int x){
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->List = NULL;
	if (Top == NULL) {
		Top = temp;
		return;
	}
	temp->List = Top;
	Top = temp;
}

void Printf(){
	Node* temp1 = Top;
	while(temp1 != NULL){
		printf("%d ",temp1->data);
		temp1 = temp1->List;
	}
	printf("\n");
}

void Pop(){
	Node* temp2 = Top;
	if (Top == NULL) return;
	Top = temp2->List;
	free(temp2);
}


