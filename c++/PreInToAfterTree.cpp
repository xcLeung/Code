/*************************************************************************
	> File Name: PreInToAfterTree.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sun 03 Nov 2013 10:03:45 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<csetjmp>
#include<exception>
using namespace std;

struct BTNode{
    int data;
    BTNode *lchild;
    BTNode *rchild;
};

void input(int *preArray,int *InArray,int length);
void output(int *array,int length);
BTNode *constructAfter(int *preArray,int *InArray,int length);
BTNode *constructCore(int *startPre,int *endPre,int *startIn,int *endIn);
void printPreDG(BTNode *root);
void printInDG(BTNode *root);
void printAfterDG(BTNode *root);


int main(){
    int n;
    cout<<"请输入数字n：";
    cin>>n;
    int *preArray=(int*)malloc(sizeof(int)*(n+5));  //malloc库函数动态申请内存
    memset(preArray,0,sizeof(preArray));
    int *InArray = new int[n+5]();               //new运算符动态申请内存
    input(preArray,InArray,n);
    cout<<"前序序列：";
    output(preArray,n);
    cout<<"中序序列：";
    output(InArray,n);
   
    BTNode *root=NULL;
    root=constructAfter(preArray,InArray,n);
    cout<<"-----------------------"<<endl;
    cout<<"前序遍历（递归）:";
    printPreDG(root);
    cout<<endl;
    cout<<"中序遍历（递归）:";
    printInDG(root);
    cout<<endl;
    cout<<"后序遍历（递归）:";
    printAfterDG(root);
    cout<<endl;
    return 0;
}

BTNode *constructAfter(int *preArray,int *InArray,int length){
    if(preArray==NULL || InArray==NULL || length==0){
        cout<<"序列为空,无法构建";
        return NULL;
    }
    return constructCore(preArray,preArray+length-1,InArray,InArray+length-1);
}


BTNode *constructCore(int *startPre,int *endPre,int *startIn,int *endIn){
    int rootVal=*startPre;
    BTNode *newNode = new BTNode();
    newNode->data=rootVal;
    newNode->lchild=NULL;
    newNode->rchild=NULL;
    
    if(startPre==endPre){
        if(startIn==endIn && *startPre==*startIn){
            return newNode;
        }
        else{
            cout<<"错误输入"<<endl;
        }
    }

    int *rootIn=startIn;
    for(;rootIn<=endIn;rootIn++){
        if(*rootIn==rootVal){
            break;
        }
    }
    if(rootIn>endIn){
        cout<<"序列非法输入";
    }

    int leftlength=rootIn-startIn;

    if(leftlength>0){
        newNode->lchild=constructCore(startPre+1,startPre+leftlength,startIn,rootIn-1);
    }
    if(leftlength<endPre-startPre){
        newNode->rchild=constructCore(startPre+leftlength+1,endPre,rootIn+1,endIn);
    }
    return newNode;
}

void printPreDG(BTNode *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        printPreDG(root->lchild);
        printPreDG(root->rchild);
    }
}

void printInDG(BTNode *root){
    if(root!=NULL){
        printInDG(root->lchild);
        cout<<root->data<<" ";
        printInDG(root->rchild);
    }
}

void printAfterDG(BTNode *root){
    if(root!=NULL){
        printAfterDG(root->lchild);
        printAfterDG(root->rchild);
        cout<<root->data<<" ";
    }
}


void input(int *preArray,int *InArray,int length){
    int val=0;
    for(int i=0;i<length;i++){
        cin>>val;
        *(preArray+i)=val;
    }
    for(int i=0;i<length;i++){
        cin>>val;
        *(InArray+i)=val;
    }
}

void output(int *array,int length){
    for(int i=0;i<length;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
}
