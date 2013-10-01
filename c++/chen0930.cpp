/*************************************************************************
	> File Name: chen0930.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 30 Sep 2013 08:19:26 PM CST
 ************************************************************************/

/*
从一个长字符串中查找包含给定字符集合的最短子串。例如，长串为“aaaaaaaaaacbebbbbbdddddddcccccc”，字符集为{abcd}，那么最短子串是“acbebbbbbd”。
如果将条件改,为“包含且只包含给定字符集合”，
*/ 
 
#include<iostream>
#include<string.h>
using namespace std;

int hasha[2000];
int hashb[2000];

void init();
void deal(char *strA,char *strB);

int main(){
    char strA[1204];
    char strB[1204];
    cout<<"请输输入字符串A"<<endl;
    cin>>strA;
    cout<<"请输入字符集B"<<endl;
    cin>>strB;
    deal(strA,strB);
    return 0;
}

void init(){
    memset(hasha,0,sizeof(hasha));
    memset(hashb,0,sizeof(hashb));
}

void deal(char *strA,char *strB){
    int lenA,lenB;
    int i,j,n,count,start=0;
    lenA=strlen(strA);
    lenB=strlen(strB);
    if(lenB>lenA){
        cout<<"串非法！"<<endl;
    }
    for(i=0;i<lenB;i++){
        hasha[strB[i]]=1;
    } 
    for(n=lenB;n<=lenA;n++){
        for(i=0;i<lenA-n+1;i++){
            count=0;
            memcpy(hashb,hasha,sizeof(hashb));
            for(j=i;j<i+n;j++){
                if(hashb[strA[j]]){
                    count++;
                    hashb[strA[j]]--;
                }
            }
            if(count==lenB){
                start=i;
                break;
            }
        }
        if(start){
            for(i=start;i<start+n;i++){
                cout<<strA[i];
            }
            cout<<endl;
            return;
        }
    }
}

