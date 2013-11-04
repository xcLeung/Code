/*************************************************************************
	> File Name: PreInToAfterTree.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sun 03 Nov 2013 10:03:45 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<map>
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
void printPreDD(BTNode *root);
void printInDD(BTNode *root);
void printAfterDD(BTNode *root);

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
    cout<<"-----------------------"<<endl;
    cout<<"前序遍历（迭代）:";
    printPreDD(root);
    cout<<"后序遍历（迭代）:";
    printInDD(root);
    cout<<"后序遍历（迭代）:";
    printAfterDD(root);

    free(preArray);
    delete InArray;
    return 0;
}

BTNode *constructAfter(int *preArray,int *InArray,int length){
    if(preArray==NULL || InArray==NULL || length==0){
        cout<<"序列为空,无法构建"<<endl;
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
            throw std::exception();
        }
    }

    int *rootIn=startIn;
    for(;rootIn<=endIn;rootIn++){
        if(*rootIn==rootVal){
            break;
        }
    }
    if(rootIn>endIn){
        throw std::exception();
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

void printPreDD(BTNode *root){
    stack<BTNode*> bnstack;
    if(root==NULL){
        cout<<"树为空"<<endl;
        return ;
    }else{
        BTNode *p=root;
        while(p!=NULL || bnstack.size()>0){
            while(p!=NULL){
                cout<<p->data<<" ";
                bnstack.push(p);
                p=p->lchild;
            }
            p=bnstack.top();
            bnstack.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}

void printInDD(BTNode *root){
    stack<BTNode*> bnstack;
    if(root==NULL){
        cout<<"树为空"<<endl;
        return ;
    }else{
        BTNode *p=root;
        while(p!=NULL || bnstack.size()>0){
            while(p!=NULL){
                bnstack.push(p);
                p=p->lchild;
            }
            p=bnstack.top();
            cout<<p->data<<" ";
            bnstack.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}

void printAfterDD(BTNode *root){
    stack<BTNode*> bnstack;
    map<BTNode*,int> bnmap;
    if(root==NULL){
        cout<<"树为空"<<endl;
        return ;
    }else{
        BTNode *p=root;
        while(p!=NULL || bnstack.size()>0){
            while(p!=NULL){
                bnstack.push(p);
                bnmap[p]=0;
                p=p->lchild;
            }
            if(bnmap[bnstack.top()]==0){
                p=bnstack.top();
                bnmap[bnstack.top()]=1;
                p=p->rchild;
            }else{
                p=bnstack.top();
                bnstack.pop();
                cout<<p->data<<" ";
                p=NULL;
            }
        } 
    }
    cout<<endl;
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
