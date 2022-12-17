#pragma once
#include<stdio.h>
#include<stdlib.h>


#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_
#endif;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};




struct Node* GetNewNode(int data);	//Creating a new Node.
void Printf();	//Printfing the List with positive direction.
void ReversePrintf();	//Printfing the List with reverse direction.
void InsertAtHead(int x);	//Inserting a Node at tht head of List. 
void InsertAtEnd(int x);	//Inserting a Node at the end of List.
void FreeNode();