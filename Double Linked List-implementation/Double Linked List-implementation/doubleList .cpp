#include "doubleList .h"
struct Node* head = NULL;
struct Node* End = NULL;

Node* GetNewNode(int data){
    Node* NewNode = (Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}

void Printf() {
    Node* temp = head;
    if (temp == NULL) return;
    printf("Positive printf:\n");

    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrintf(){   
    Node* temp = head;
    if (temp == NULL) return;
    while (temp->next != NULL) {    //����ж����������� temp != NULL;����Զ��ӡ���������ġ�
      //  printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("Reverse printf:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");

}

void InsertAtHead(int x){
    Node* temp = GetNewNode(x);
    if (head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtEnd(int x){
    Node* temp = GetNewNode(x);
    if (head == NULL) {
        head = End = temp;
        return;
    }
    else {
        /*
        Node* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
        temp->next = NULL;
        */

        /* ����ʱ��д�� */
        Node* temp1 = End;
        End->next = temp;
        temp->prev = End;
        End = temp;
    }
}
void FreeNode() {
    Node* h = head;
    Node* temp3 = h->next;
    while (temp3->next != NULL) {
        free(h);
        h = temp3;
        temp3 = temp3->next;
    }
//    Node* temp4 = h;
    free(h);
    head = NULL;
}
