#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1e9
struct Edge{
    int u,v;
    int w;
};

struct Edge edges[50010];
int parent[1010];
int n,m;
int ans;

bool cmp(const struct Edge &e1,const struct Edge &e2){
    return e1.w>e2.w;
}

void Init(){
    ans=maxn;
    memset(edges,0,sizeof(edges));
    memset(parent,0,sizeof(parent));
}

void Input(){
    int u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edges[i].u=u;
        edges[i].v=v;
        edges[i].w=w;
    }
}

void SetData(){
    for(int i=1;i<=n;i++)
        parent[i]=i;
}

void print_data(){
    for(int i=0;i<m;i++){
        cout<<"点1 "<<edges[i].u;
        cout<<"点2 "<<edges[i].v;
        cout<<"权重 "<<edges[i].w<<endl;
    }
}

int Find(int x){
    if(x==parent[x])
        return x;
    else
        parent[x]=Find(parent[x]);
    return parent[x];
}

void Combine(int x,int y){
    int fx,fy;
    fx=Find(x);
    fy=Find(y);
    parent[fx]=fy;
}

void Deal(){
    sort(edges,edges+m,cmp);
    //print_data();
    Edge *e;
    for(int i=0;i<m;i++){
        e=&edges[i];
        //cout<<"权重："<<e->w<<endl;
        if(Find(e->u)!=Find(e->v)){
            if(ans>e->w)
                ans=e->w;
            Combine(e->u,e->v);
            if(Find(1)==Find(n)){
                return ;
            }
        }
    }
}

void Output(){
    printf("%d\n",ans);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        Init();
        Input();
        SetData();
        Deal();
        Output();
    }
    return 0;
}
