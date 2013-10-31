/*************************************************************************
	> File Name: list.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Thu 31 Oct 2013 12:40:57 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct LNode{
    int data;
    LNode *next;
};

void print(LNode *head);
void printReverse(LNode *head);
void addToTail(LNode **head,int value);
void addToHead(LNode **head,int value);

int main(){
    int n,val;
    LNode *head=NULL;
    cout<<"请输入数字n：";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        addToTail(&head,val);
    }
    addToHead(&head,16);
    addToHead(&head,24);
    print(head);
    printReverse(head);
    cout<<endl;
    return 0;
}

void print(LNode *head){
    LNode *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void printReverse(LNode *head){
    if(head!=NULL){
        if(head->next!=NULL){
            printReverse(head->next);
        }
        cout<<head->data<<" ";
    }
}

void addToTail(LNode **head,int value){
    LNode *newNode = new LNode();
    newNode->data=value;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        LNode *p=*head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newNode;
    }
}

void addToHead(LNode **head,int value){
    LNode *newNode=new LNode();
    newNode->data=value;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        newNode->next=*head;
        *head=newNode;
    }
}


