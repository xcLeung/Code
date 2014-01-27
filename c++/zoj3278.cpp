#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long

int n,m;
int boy[100010],girl[100010];
LL llMin,llMax,llmid,ans,k;

bool cmp(int a,int b){
    return a>b;
}

void Init(){
    memset(boy,0,sizeof(boy));
    memset(girl,0,sizeof(girl));
}

void Input(){
    int i;
    for(i=0;i<n;i++)
        cin>>boy[i];
    for(i=0;i<m;i++)
        cin>>girl[i];
}

int main()
{
    while(cin>>n>>m>>k){
        Init();
        Input();
        sort(boy,boy+n,cmp);
        sort(girl,girl+m,cmp);
        llMin=1ll*boy[n-1]*girl[m-1];
        llMax=1ll*boy[0]*girl[0];
        ans=llMin;
        //cout<<"最小值 "<<llMin<<endl;
        //cout<<"最大值 "<<llMax<<endl;
        while(llMin<=llMax){
            LL iSum=0;
            llmid=(llMin+llMax)>>1;
            //cout<<"外围"<<llMin<<" "<<llMax<<" "<<llmid<<endl;
            int low,high,mid;
            for(int i=0;i<n;i++){
                low=0;
                high=m;
                LL iTmpSum=0;
                while(low<high){
                    mid=(low+high)>>1;
                    if(1ll*boy[i]*girl[mid]>=llmid){
                        iTmpSum=mid+1;
                        low=mid+1;
                    }
                    else{
                        high=mid;
                    }
                }
              //  cout<<"大于llmid个数 "<<iTmpSum<<endl;
                iSum+=iTmpSum;
            }
            //cout<<"llmid "<<llmid<<endl;
            //cout<<"比llmid大的数目 "<<iSum<<endl;
            if(iSum>=k){
                ans=llmid;
               // cout<<"答案"<<ans<<endl;
                llMin=llmid+1;
            }
            else{
                llMax=llmid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
