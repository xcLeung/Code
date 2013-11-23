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
void addToIndex(LNode **head,int value,int index);
void deleteNode(LNode **head,int value);
LNode *reverseListDG(LNode **head,LNode *p);
LNode *reverseListDD(LNode **head);
void mergeList(LNode **lc,LNode *la,LNode *lb);
LNode* interset(LNode *firstLinkt,LNode *secondLink);


int main(){
    int n,val;
    LNode *head=NULL,*rhead=NULL;
    cout<<"请输入数字n：";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        addToTail(&head,val);
    }
    //addToHead(&head,16);
    //addToIndex(&head,24,3);
    //deleteNode(&head,4);
    cout<<"原来的序列：";
    print(head);
    cout<<"逆序输出：";
    printReverse(head);
    cout<<endl;
    reverseListDG(&rhead,head);
    cout<<"链表逆序后的输出：";
    print(rhead);
    cout<<"链表再逆序后的输出：";
    head=reverseListDD(&rhead);
    print(head);

    cout<<"------------------------------"<<endl;
    LNode *la=NULL;
    LNode *lb=NULL;
    LNode *lc=NULL;
    for(int i=0;i<10;i++){
        if(i%2){
            addToTail(&la,i);
        }else{
            addToTail(&lb,i);
        }
    }
    mergeList(&lc,la,lb);
    cout<<"合并两个有序链表："<<endl;
    print(lc);

    cout<<"------------------------------"<<endl;
    la=lb=lc=NULL;
    cout<<"链表交集："<<endl;
    addToTail(&la,1);
    addToTail(&la,5);
    addToTail(&la,7);
    addToTail(&la,8);
    print(la);
    addToTail(&lb,2);
    addToTail(&lb,4);
    addToTail(&lb,5);
    addToTail(&lb,8);
    addToTail(&lb,9);
    print(lb);
    lc=interset(la,lb);
    print(lc);
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

void addToIndex(LNode **head,int value,int index){
    LNode *newNode=new LNode();
    newNode->data=value;
    newNode->next=NULL;
    int count=1;
    if(*head==NULL){
        *head=newNode;
    }else if(index==1){
        newNode->next=*head;
        *head=newNode;
    }else{
        LNode *pre=*head;
        LNode *p=*head;
        while(p!=NULL && count!=index){
            pre=p;
            p=p->next;
            count++;
        }
        newNode->next=p;
        pre->next=newNode;
    }
}

void deleteNode(LNode **head,int value){
    LNode *toDelete=NULL;
    LNode *p;
    if(*head==NULL){
        cout<<"链表为空，无法删除"<<endl;
        return ;
    }else if((*head)->data==value){
        toDelete=*head;
        *head=(*head)->next;
    }else{
        p=*head;
        while(p->next!=NULL && p->next->data!=value){
            p=p->next;
        }
        if(p->next!=NULL && p->next->data==value){
            toDelete=p->next;
            p->next=p->next->next;
        }
    }
    if(toDelete!=NULL){
        delete toDelete;
        toDelete=NULL;
    }
}

LNode *reverseListDG(LNode **head,LNode *p){
    //cout<<p->data<<endl;
    if(p==NULL){
        cout<<"头指针为空"<<endl;
        return NULL;
    }
    if(p->next==NULL){
        *head=p;
        return p;
    }
    reverseListDG(head,p->next)->next=p;
    p->next=NULL;
    return p;
}

LNode *reverseListDD(LNode **head){
    if(*head==NULL){
        cout<<"头指针为空"<<endl;
        return NULL;
    }else{
        LNode *p=*head;
        LNode *pre=NULL;
        LNode *next=(*head)->next;
        while(next!=NULL){
            p->next=pre;
            pre=p;
            p=next;
            next=next->next;
        }
        p->next=pre;
        return p;
    }
}

void mergeList(LNode **lc,LNode *la,LNode *lb){
    LNode *p=la;
    LNode *q=lb;
    LNode *res;
    if(p->data>=q->data){
        *lc=res=lb;
        q=q->next;
    }else{
        *lc=res=la;
        p=p->next;
    }
    while(p && q){
        if(p->data<=q->data){
            res->next=p;
            res=p;
            p=p->next;
        }else{
            res->next=q;
            res=q;
            q=q->next;
        }
    }
    res->next=p?p:q;
}

LNode* interset(LNode *firstLink,LNode *secondLink){
    LNode *p=firstLink;
    LNode *q=secondLink;
    LNode *resHead=NULL;
    LNode *res=NULL;
    while(p && q){
        if(p->data<q->data){
            p=p->next;
        }else if(p->data>q->data){
            q=q->next;
        }else{
            LNode *newNode=new LNode();
            newNode->data=p->data;
            newNode->next=NULL;
            if(resHead==NULL){
                res=newNode;
                resHead=res;
            }else{
                res->next=newNode;
                res=res->next;
            }
            p=p->next;
            q=q->next;
        }
    }
    return resHead;
}
