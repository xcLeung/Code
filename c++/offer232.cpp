/*************************************************************************
	> File Name: offer232.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Tue 22 Oct 2013 12:19:51 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*
 * 思考：当要对串或数组进行变长的距离，从头开始扫描将要移动后来的元素，这是无谓的。
 *       这时不妨申请足够的空间，然后从尾到头开始扫描完成操作
 */


//将字符串的空格转化为%20
void replaceString(char *str,int len){
    if(str==NULL || len<=0)
        return ;
    int i=0,count=0;
    char *p,*q;
    for(i=0;i<len;i++){
        if(*(str+i)==' '){
            count++;
        }
    }
    p=str+len;
    q=str+len+count*2;
    while(p>=str){
        if(*p==' '){
            *q--='0';
            *q--='2';
            *q--='%';
            p--;
        }else{
            *q=*p;
            p--;
            q--;
        }
    } 
    cout<<str<<endl;
    return ;
}

int main(){
    char *str;
    str=(char*)malloc(sizeof(char)*1000);
    gets(str);
    cout<<strlen(str)<<endl;
    replaceString(str,strlen(str));
    free(str);
	str=NULL;
    return 0;
}
