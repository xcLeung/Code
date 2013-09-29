/*************************************************************************
	> File Name: chen0924.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sun 29 Sep 2013 10:24:14 AM CST
 ************************************************************************/

 /*
 给定字符串，找到它的最长回文子串，都有哪些思路呢？例
 如"adaiziguizhongrenenrgnohziugiziadb",回文字串很多了，但最长的
 是"daiziguizhongrenenrgnohziugiziad"
 */
 
#include<iostream>
#include<string.h>
using namespace std;

int dp[1300][1300];

void deal(char *str){
    int i,j,l;
    int len=strlen(str);
    int max=0,start=0,end=0;
    for(l=2;l<=len;l++){
        for(i=0;i<len-l+1;i++){
            j=i+l-1;
            if(l==2){
                dp[i][j]=(str[i]==str[j]);
            }else{
                dp[i][j]=dp[i+1][j-1] && (str[i]==str[j]);
            }
            cout<<"dp[i][j]"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            if(dp[i][j] && j-i>max){
                max=j-i;
                start=i;
                end=j;
            }
        }
    }
   /* for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            if(i==j){
                dp[i][j]=1;
            }
            else if(i+1==j){
                dp[i][j]=str[i]==str[j];
            }else{
                dp[i][j]=dp[i+1][j-1] && (str[i]==str[j]);
            }
            cout<<"dp[i][j] "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            if(dp[i][j] && j-i>max){
                max=j-i;   
                start=i;
                end=j;
            }
        }
    }
    */
    cout<<"length:"<<len<<endl;
    cout<<"start:"<<start<<endl;
    cout<<"end:"<<end<<endl;
    for(i=start;i<=end;i++){
        cout<<str[i];
    }
    cout<<endl;
    return ;
}

void init(){
    memset(dp,1,sizeof(dp));
}

int main(){
    char str[1204];
    cin>>str;
    init();
    deal(str);
    return 0;
}
