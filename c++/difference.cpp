/*************************************************************************
	> File Name: difference.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sat 05 Oct 2013 10:45:02 PM CST
 ************************************************************************/

 /*
 已知集合A和B的元素分别用不含头结点的单链表存储，函数difference()用于求解集合A与B的差集，并将结
 果保存在集合A的单链表中。例如，若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A=
 {10,20,30}。
 */
 
#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int elem;
    node *next;
};

void difference(node *La,node *Lb){
    node *pa,*pb,*q,*pre;
    pa=La;
    while(pa){   //外层循环遍历A集合
        pb=Lb;
        while(pb && pa->elem!=pb->elem){  //内层循环遍历B集合
            pb=pb->next;
        }
        if(pb){  //找到删除pa指向的节点
            if(!pre){
                La=pa->next;
            }else{
                pre->next=pa->next;
            }
            q=pa;
            pa=pa->next;
            free(q);
        }else{ //未找到指向下一个节点，并维持前驱关系
            pre=pa;
            pa=pa->next;
        }
    }
}

int main(){
    return 0;
}
