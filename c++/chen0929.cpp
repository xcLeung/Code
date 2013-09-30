/*************************************************************************
	> File Name: chen0929.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sun 29 Sep 2013 11:53:44 PM CST
 ************************************************************************/

 /*给定两个字符串A和B，判断A中是否包含由B中字符重新排列成的新字符串。例如：A=abcdef, B=ba，结果应该返回true。因为ba的排列ab，是A的子串。*/
 
#include<iostream>
#include<string.h>
using namespace std;

int hashb[2000];
int hasha[2000];

void init(){
    memset(hashb,0,sizeof(hashb));
    memset(hasha,0,sizeof(hasha));
}


int deal(char *strA,char *strB){
    int lenA,lenB;
    int i,j,count;
    lenA=strlen(strA);
    lenB=strlen(strB);
    if(lenA<lenB){
        return 0;
    }
    for(i=0;i<lenB;i++){
        hasha[strB[i]]++;
    }
    for(i=0;i<lenA-lenB+1;i++){
        count=0;
        memcpy(hashb,hasha,sizeof(hashb));
        for(j=i;j<i+lenB;j++){
            if(!hashb[strA[j]]){
                break;
            }else{
                hashb[strA[j]]--;
                count++;
            }
        }
        if(count==lenB){
            return 1;
        }
    }
    return 0;
}

int main()
{
    char strA[1204];
    char strB[1204];
    cout<<"请输入A串和B串"<<endl;
    cin>>strA>>strB;
    init();
    cout<<deal(strA,strB)<<endl;
    return 0;
}
