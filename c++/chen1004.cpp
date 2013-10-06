/*************************************************************************
	> File Name: chen1004.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 04 Oct 2013 02:11:04 PM CST
 ************************************************************************/
/*
N个孩子站成一排，每个人分给一个权重。按照如下的规则分配糖果： 
每个孩子至少有一个糖果；所分配权重较高的孩子，会比他的邻居获得更多的糖
果。 问题是，最少需要多少个糖果？
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> init(int n){
    vector<int> w;
    int i,a;
    for(i=0;i<n;i++){
        cin>>a;
        w.push_back(a);
    }
    return w;
}

int deal(vector<int> w){
    int count=0;
    vector<int> ivec(w.size(),1);
    vector<int>::size_type i,j;
    for(i=1;i<w.size();i++){
        if(w[i]>w[i-1]){
            ivec[i]=ivec[i-1]+1;
        }else if(w[i]<=w[i-1]){
            ivec[i]=1;
        }
    }
	for(i=w.size()-1;i>0;i--){
        if(w[i]<w[i-1] && ivec[i]>=ivec[i-1]){
            ivec[i-1]=ivec[i]+1;
        }
    }
    for(vector<int>::iterator iter=ivec.begin();iter<ivec.end();iter++){
        cout<<*iter<<" ";
        count+=*iter;
    }
    cout<<endl;
    return count;
}


int main(){
    int n;
    cout<<"请输入人数：";
    cin>>n;
    vector<int> w=init(n);
    cout<<deal(w)<<endl;
    return 0;
}
