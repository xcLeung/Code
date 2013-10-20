/*************************************************************************
	> File Name: findNumInArray.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 04 Oct 2013 12:59:58 AM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int arr[][3] = {{1,2,5},{3,4,13},{7,11,17}};


int search(int *arr,int n,int key){
    int left=0,right=n;
    int mid;
    while(left<right){
        mid=(left+right)>>1;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            right=mid;
        }
        else if(key>arr[mid]){
            left=mid+1;
        }
    }
    return -1;
}

int check(int array[][3],int m,int n,int key){
    int i,col;
    for(i=0;i<m;i++){
        col=search(array[i],n,key);
        if(col!=-1){
            return 1;
        }
    }
    return 0;
}

int deal(int array[][3],int m,int n,int key){
    int i,j;
    if(array && m>=0 && n>=0){
        i=0,j=n-1;
        while(i<m && j>=0){
            if(array[i][j]==key){
                return 1;
            }else if(array[i][j]<key){
                i++;
            }else if(array[i][j]>key){
                j--;
            }
        }
    }
    return 0;
}

int main(){
    int num=0;
    cout<<"请输入要查找的数字：";
    cin>>num;
    cout<<check(arr,3,3,num)<<endl;
    cout<<deal(arr,3,3,num)<<endl;
    return 0;
}
