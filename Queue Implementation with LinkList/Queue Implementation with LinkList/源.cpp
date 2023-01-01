/*
 *DataStruct Test
 *Using Array of loops 
 *Authored by Haiyang.Zhao
 */

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

void Enqueue(int* Array, int data);
void Dequeue();
bool isFull();
bool IsEmpty();
int Front(int* Array);


int front = -1;		//表征队列头
int rear = -1;		//表征队列尾
int size = 0;	

void Enqueue(int* Array, int data) {
	if (isFull()) return;
	else if (IsEmpty()) {
		front = rear = 0;
		Array[rear] = data;
	}
	else {
		rear = (rear + 1)%size;
		Array[rear] = data;
	}
}

void Dequeue() {
	if (IsEmpty()) {
		return;
	}
	else if (rear == front) { front = rear = -1; }
	else {
		front = (front + 1)%size;
	}
}

bool isFull() {
	if (((rear + 1) % size) == front) {
		printf("Queue is Full!\n");
		return true;
	}
	else
		return false;
}

bool IsEmpty() {
	if (rear == -1 && front == -1) {
		return true;
	}
	else return false;
}

int Front(int* Array){
	if(front!=-1)
	return Array[front];
}


int main() {
	int Array[10];		//利用数组完成队列的实现
	//int* head = NULL;
	memset(Array, 0, sizeof(Array));	//初始化数组

	size = sizeof(Array) / sizeof(int);		//计算数组中元素的个数
	Enqueue(Array, 0);		//在队列尾部加数据
	Enqueue(Array, 1);
	Enqueue(Array, 2);
	Dequeue();
	Enqueue(Array, 3);
	Enqueue(Array, 4);
	Enqueue(Array, 5);
	Enqueue(Array, 6);
	Dequeue();
	Enqueue(Array, 7);
	Enqueue(Array, 8);
	Enqueue(Array, 9);
	Enqueue(Array, 10);
	Enqueue(Array, 11);

	/*
	*Enqueue(Array, 5);
	*Enqueue(Array, 6);
	*Enqueue(Array, 7);
	*Enqueue(Array, 8);
	*Enqueue(Array, 9);
	*Enqueue(Array,10);
	*Enqueue(Array,11);
	*Enqueue(Array, 12);
	*/

	
	if (rear > front) {
		for (int ii = front; ii < rear + 1; ii++) {
			printf("%d ", Array[ii]);

		}
	}	
	
	if (rear < front) {
		for (int jj = front; jj < rear+size+1; jj++) {
			printf("%d ", Array[jj%size]);

		}
	}
	

	//head = Enqueue(Array, 3);

	/*
	 *for (int ii = 0; ii < 10; ii++) {
	 *	printf("%d ",Array[ii]);
	 *}
	 *printf("%d ",size);
	*/
}


