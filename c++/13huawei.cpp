/*************************************************************************
	> File Name: 13huawei.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Thu 10 Oct 2013 12:09:07 AM CST
 ************************************************************************/

 /*将多个以空格分隔的串，转成逗号分隔*/
 
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void DivideString(const char *inputStr,long inputLen,char *outputStr){
    int i=0,j=0;
    bool flag=true;
    for(i=0;*(inputStr+i)==' ';i++);
    for(j=0;i<inputLen;i++){
        if(' '!=*(inputStr+i)){
            outputStr[j++]=*(inputStr+i);
            if(!flag)
                flag=true;
        }else{
            if(flag)
                outputStr[j++]=',';
            flag=false;
        }
    }
    outputStr[j++]=',';
    outputStr[j++]='\0';
}

int main(){
    char *output;
    string str;
    getline(std::cin,str);
    output=(char*)malloc(sizeof(char)*(str.size()+1));
    DivideString(str.c_str(),(long)str.size(),output);
    cout<<output<<endl;
    return 0;
}
