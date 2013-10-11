/*************************************************************************
	> File Name: chen1010.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Thu 10 Oct 2013 11:03:31 PM CST
 ************************************************************************/

 /*陈面试题10-10 最新版本 给出如下形式的串1.1.2，1.12 求出最新的版本号 ans:1.12 */
 
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

vector<int> compare(const vector<int> a,const vector<int> b){
    vector<int>::size_type ax=0;
    vector<int>::size_type bx=0;
    while(ax<a.size() && bx<b.size()){
        if(a[ax]>b[bx]){
            return a;
        }else if(a[ax]<b[bx]){
            return b;
        }else{
            ax++;
            bx++;
        }
    }
    if(ax>=a.size() || bx>=b.size()){
        if(a.size()<b.size()){
            return b;
        }else
        {
            return a;
        }
    }
    return a;
}

void deal(const char* str){
    vector<int> ans_vec;
    vector<int> com_vec;
    int len=strlen(str);
    int i,num=0,count=0;
    for(i=0;i<len;i++){
        if(*(str+i)==','){
            if(count==0){
                ans_vec.push_back(num);
            }else{
                com_vec.push_back(num);
            }
            //cout<<num<<endl;
            num=0;
            count++;
            ans_vec=compare(ans_vec,com_vec);
            com_vec.clear();
        }
        if(*(str+i)>='0' && *(str+i)<='9'){
            num*=10;
            num+=*(str+i)-'0';
        }
        if(*(str+i)=='.'){
            if(count==0){
                ans_vec.push_back(num);
            }else{
                com_vec.push_back(num);
            }
            //cout<<num<<endl;
            num=0;
        }
    }
    com_vec.push_back(num);
    ans_vec=compare(ans_vec,com_vec);
    com_vec.clear();
    for(vector<int>::iterator iter=ans_vec.begin();iter<ans_vec.end();iter++){
        if(iter==ans_vec.end()-1){
            cout<<*iter<<endl;
        }else{
            cout<<*iter<<".";
        }    
    }
}

int main(){
    string str;
    getline(std::cin,str);
    deal(str.c_str());
    return 0;
}
