#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/*
给一个数字串，比如12259，映射到字母数组，比如，1 -> a， 2-> b，... ， 12 -> l ，... 26-> z。
那么，12259 -> lyi 或 abbei 或 lbei 或 abyi。输入一个数字串，判断是否能转换成字符串，如果能，则打印所以有可能的转换成的字符串。
*/

char character[30];

void init(){
	for(int i=0;i<26;i++){
		character[i]='a'+i;
    cout<<character[i]<<" "<<i+1<<" ";
    }
	cout<<endl;	
}


void deal2(char *str,int t,int len,char *ans,int count){
    int res=0;
    if(t>=len)
    {
       *(ans+count)='\0';
        cout<<ans<<endl;
        return ;
    }
    ans[count]=character[str[t]-'0'-1];
   // cout<<character[str[t]-'0'-1];
    deal2(str,t+1,len,ans,count+1);
    if(t+1<len){
        if(str[t]=='1' || str[t]=='2'){
            res=(str[t]-'0')*10+(str[t+1]-'0');
            ans[count]=character[res-1];
            deal2(str,t+2,len,ans,count+1);
        }
    }
    return ;
}

int main(){
	init();
	char str[1204];
    char ans[1204];
    cin>>str;	
	int len=strlen(str);
	cout<<"length:"<<len<<endl;
    if(len){
        deal2(str,0,len,ans,0);   
    }
    
	return 0;
}
