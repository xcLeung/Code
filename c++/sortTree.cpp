/*************************************************************************
	> File Name: sortTree.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sun 24 Nov 2013 03:41:03 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;

struct TNode{
    int data;
    TNode *lchild,*rchild;
};

bool searchTree(TNode *root,TNode **p,TNode *f,int data);
void insertTree(TNode **root,int data);
void PreOrderTraverse(TNode *root);
void InorderTraverse(TNode *root);
TNode *find(TNode *root,int max_index);

int main(){
   TNode *root=NULL;
    int n,num;
    cout<<"请输入数字：";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        insertTree(&root,num);
    }
    PreOrderTraverse(root);
    cout<<endl;
    InorderTraverse(root);
    cout<<endl;

    TNode *res=find(root,3);
    cout<<res->data<<endl;
    return 0;
}

bool searchTree(TNode *root,TNode **p,TNode *f,int data){
    if(root==NULL){
        *p=f;
        return false;
    }else if(root->data<data){
        return searchTree(root->rchild,p,root,data);
    }else{
        return searchTree(root->lchild,p,root,data);
    }
}

void insertTree(TNode **root,int data){
    TNode *p,*f;
    if(!searchTree(*root,&p,NULL,data)){
       TNode *newNode = new TNode();
        newNode->data=data;
        newNode->lchild=NULL;
        newNode->rchild=NULL;
        if(*root==NULL){
           *root=newNode; 
        }else{
            if(data<=p->data){
                p->lchild=newNode;
            }else{
                p->rchild=newNode;
            }
        }
    }
    return ;
}

void PreOrderTraverse(TNode *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }
}

void InorderTraverse(TNode *root){
    if(root!=NULL){
        InorderTraverse(root->lchild);
        cout<<root->data<<" ";
        InorderTraverse(root->rchild);
    }
    return ;
}

TNode *find(TNode *root,int index){
    int count=0;
    stack<TNode*> tstack;
    if(root==NULL){
        cout<<"树为空"<<endl;
        return NULL;
    }else{
        TNode *p=root;
        while(p!=NULL || tstack.size()>0){
            while(p!=NULL){
                tstack.push(p);
                p=p->rchild;
            }
            p=tstack.top();
            count++;
            if(count==index){
                return p;
            }
            tstack.pop();
            p=p->lchild;
        }
    }
}
