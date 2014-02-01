#include <iostream>
#include <cstring>
using namespace std;

int n,ans;
int a[1010],dp[1010];

int Max(int a,int b){
    return a>b?a:b;
}

void Init(){
    ans=0;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
}

void Input(){
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i]=1;
    }
}

void Solve(){
    if(n==1){
        ans=1;
        return ;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((dp[j]%2==1 && a[i]<a[j]) || (dp[j]%2==0 && a[i]>a[j])){
                dp[i]=Max(dp[j]+1,dp[i]);
            }
        }
        if(ans<dp[i])
            ans=dp[i];
    }
}

void Output(){
    cout<<ans<<endl;
}

int main()
{
    while(true){
        cin>>n;
        if(!n)
            break;
        Init();
        Input();
        Solve();
        Output();
    }
    return 0;
}
