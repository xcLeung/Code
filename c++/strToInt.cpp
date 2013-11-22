/*************************************************************************
	> File Name: strToInt.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Fri 22 Nov 2013 12:19:36 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int strToInt(const char *str);
const int power(int num,int e);

int main(){
    char *str=NULL;
    str=(char*)malloc(sizeof(char)*1000);
    cout<<"请输入字符串：";
    cin>>str;
    cout<<strToInt(str)<<endl;
    return 0;
}

const int strToInt(const char *str){
    cout<<str<<endl;
    int len=strlen(str);
    int num=0;
    if(str==NULL || len<=0){
        cout<<"参数为空"<<endl;
        return 0;
    }
    for(int b=0,i=len-1;i>=0;i--,b++){
        if(*(str+i)>='A' && *(str+i)<='Z'){
            //cout<<power(26,b)*(*(str+i)-'A'+1)<<endl;
            num+=power(26,b)*(*(str+i)-'A'+1);
          
        } else{
            cout<<"参数符号有误"<<endl;
            return 0;
        }
    }
    return num;
}

const int power(int num,int e){
    int res=1;
    for(int i=0;i<e;i++){
        res*=num;
    }
    return res;
}
