#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

string Expert[30];
int T,n;
int Restraintmap[10][10],visited[10],a[10];
int anscnt,ans[1000][10];

void Init(){
    anscnt=0;
    memset(a,0,sizeof(a));
    memset(Restraintmap,0,sizeof(Restraintmap));
    memset(visited,0,sizeof(visited));
    memset(ans,0,sizeof(ans));
}

bool cmp(int a,int b){
    return Expert[a]<Expert[b];
}

void Input(){
    int i,j,k,idx,cnt;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>Expert[i];
        a[i]=i;
    }
    //sort(Expert,Expert+n);
    //sort(a,a+n,cmp);
    //for(i=0;i<n;i++){
    //    cout<<a[i]<<endl;
    //}
    char sTmp[30];
    for(i=0;i<n;i++){
        cin>>k;
        for(j=0;j<k;j++){
            cin>>sTmp;
            for(idx=0;idx<n;idx++){
                if(strcmp(sTmp,Expert[idx].c_str())==0){
                    Restraintmap[i][idx]=1;
                    break;
                }
            }
        }
    }
}

int Check(int me[10],int other[10]){
    int num1=0,num2=0;
    while(num1<n && num2<n){
        if(Restraintmap[other[num2]][me[num1]])
            num1++;
        else
            num2++;
    }
    return num1<num2;
}

void dfs(int dept,int *tmp){
    if(dept>=n){
        for(int i=0;i<n;i++){
            ans[anscnt][i]=tmp[i];
        }
        anscnt+=1;
    }
    for(int i=0;i<n;i++){
        if(visited[i])
            continue;
        visited[i]=1;
        tmp[dept]=i;
        dfs(dept+1,tmp);
        visited[i]=0;
    }
}

int Solve(){
    int tmp[10];
    memset(tmp,0,sizeof(tmp));
    dfs(0,tmp);
    for(int i=0;i<anscnt;i++){
        bool flag=true;
        for(int j=0;j<anscnt;j++){
            if(!Check(ans[i],ans[j])){
                flag=false;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
    return -1;
}

void Output(int caseid,int id){
    cout<<"Case "<<caseid<<": ";
    if(id==-1)
        cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(int i=0;i<n;i++){
            cout<<Expert[ans[id][i]];
            if(i!=n-1)
                cout<<" ";
            else
                cout<<endl;
        }
    }
}

int main()
{
    int id;
    cin>>T;
    for(int i=1;i<=T;i++){
        Init();
        Input();
        id=Solve();
        Output(i,id);
    }
    return 0;
}
