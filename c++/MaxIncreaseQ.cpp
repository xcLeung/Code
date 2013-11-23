/*************************************************************************
	> File Name: MaxIncreaseQ.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Fri 22 Nov 2013 10:34:06 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Result{
    int offset;
    int count;
};

void findCount(int Array[],int count,struct Result *result){
    if(Array==NULL || count<0 || result==NULL){
        cout<<"参数为空"<<endl;
        return ;
    }else{
        int resIndex=0,res=1;
        int *dp=(int*)malloc(sizeof(int)*count);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<count;i++){
            if(Array[i]>=Array[i-1]){
                dp[i]=dp[i-1]+1;
            }else{
                dp[i]=1;
            }
            if(dp[i]>res){
                res=dp[i];
                resIndex=i-res+1;
            }
        }
        delete[] dp;
        result->offset=resIndex;
        result->count=res;
    }
}

int main(){
    int array[100]={0};
    int n;
    cout<<"请输入数字n：";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    struct Result *res=(struct Result*)malloc(sizeof(struct Result));
    findCount(array,n,res);
    cout<<"偏移位置："<<res->offset<<endl;
    cout<<"长度："<<res->count<<endl;
    delete res;
    return 0;
}
