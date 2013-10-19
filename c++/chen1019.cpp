/*************************************************************************
	> File Name: chen1019.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sat 19 Oct 2013 10:24:24 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
* 输入一个字符串计算至少添加多少个字符可构成回文串
* */

void my_memset(int **a,int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            a[i][j]=0;
        }
    }
}

int min(int a,int b){
    return a<b?a:b;
}


//动态规划迭代做法
int deal(const char* str){
    int len=strlen(str),i;
    int l,h;
    int **a=(int**)malloc(sizeof(int*)*(len+2));
    for(i=0;i<len+2;i++){
        a[i]=(int*)malloc(sizeof(int)*(len+2));
    }
    my_memset(a,len+2,len+2);
    for(i=1;i<len;i++){
        for(l=0,h=i;h<len;++l,++h){
            a[l][h]=(str[l]==str[h])?a[l+1][h-1]:(min(a[l][h-1],a[l+1][h])+1);
        }
    }
    return a[0][len-1];
}

//递归做法
int deal1(const char* str,int l,int h){
    if(l>=h)
        return 0;
    if(str[l]==str[h]){
        return deal1(str,l+1,h-1);
    }else{
        return min(deal1(str,l+1,h),deal1(str,l,h-1))+1;
    }
}

int main(){
    int res=0,res1=0;
    string str;
    cin>>str;
    res=deal(str.c_str());
    cout<<"迭代："<<res<<endl;
    res1=deal1(str.c_str(),0,str.size()-1);
    cout<<"递归："<<res1<<endl;
    return 0;
}
