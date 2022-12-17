#include<stdio.h>
#include<stack>
#include<iostream>

using namespace std;

void Reverse(char* C,int n);

int main() {
	char C[20];
	printf("please enter a string\n");
	gets_s(C);
	Reverse(C,strlen(C));
	printf("The string after reverse is \n%s\n",C);

}

void Reverse(char* C, int n){
	stack<char> Sstack;
	for (int i = 0; i < n; i++) {
		Sstack.push(C[i]);
	}
	for (int i = 0; i < n; i++) {
		C[i] = Sstack.top();
		Sstack.pop();
	}

}
