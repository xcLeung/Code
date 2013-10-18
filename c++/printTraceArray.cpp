/*************************************************************************
	> File Name: printTraceArray.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Wed 16 Oct 2013 12:23:22 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

/*
 * 打印螺旋数组
 * 注意二维数组动态申请。先申请n行指针，再循环每行申请需要的列空间。
*/

void printTraceArray(int n,int m){
    int dir=3;
    int i,j,k;
    int **a;
    a=(int **)malloc(sizeof(int*)*(n+1));
    for(i=0;i<n+1;i++){
        a[i]=(int*)malloc(sizeof(int)*(m+1));
    }
    
    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){
            a[i][j]=0;
        }
    }
    for(i=0,j=0,k=0;k<n*m;){
        //cout<<k<<endl;
        //cout<<"dir:"<<dir<<" i:"<<i<<" j:"<<j<<endl;
        if(dir==0){   //上
            if(i>0 && !a[i][j]){
                a[i--][j]=k++;
            }else{
                dir=3;
                i++;
                j++;
            }
        }
        if(dir==1){  //下
            if(i<n && !a[i][j]){
                a[i++][j]=k++;
            }else{
                dir=2;
                i--;
                j--;
            }
        }
        if(dir==2){ //左
            if(j>=0 && !a[i][j]){
                a[i][j--]=k++;
            }else{
                dir=0;
                j++;
                i--;
            }
        }
        if(dir==3){ //右
            if(j<m && !a[i][j]){
                a[i][j++]=k++;
            }else{
                dir=1;
                i++;
                j--;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}

int main(){
    int n,m;
    cin>>n>>m;
    printTraceArray(n,m);
    return 0;
}
