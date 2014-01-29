#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point{
    int x,y;
    int num;
};

Point points[1010];
int xpoint[1010];
int n,R;
int ans;

bool cmp(const struct Point &p1,const struct Point &p2){
    return p1.y<p2.y;
}

void Init(){
    ans=0;
    memset(points,0,sizeof(points));
}

void Input(){
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        points[i].x=x;
        points[i].y=y;
    }
}

void Solve(){
    int i,j;
    sort(points,points+n,cmp);
    for(i=0;i<n;i++){
        int xcnt=0;
        for(j=i+1;j<n;j++){
            if(points[j].y-points[i].y<=R){
                xpoint[xcnt++]=points[j].x;
            }
        }
        xpoint[xcnt++]=points[i].x;
        sort(xpoint,xpoint+xcnt);
        int idx=0;
        for(j=0;j<xcnt;j++){
            while(xpoint[idx]-xpoint[j]<=R){
                idx++;
                if(idx>=xcnt)
                    break;
            }
            if(ans<idx-j){
                ans=idx-j;
            }
        }
    }
}

void Output(){
    cout<<ans<<endl;
}

int main()
{
    while(cin>>n>>R){
        Init();
        Input();
        Solve();
        Output();
    }
    return 0;
}
