/*************************************************************************
	> File Name: 09xunlei.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sun 06 Oct 2013 10:03:04 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;

//计算两个数相除的循环节，无则无输出
char *get_circle_digits(unsigned k,unsigned j){
    unsigned a=k,b=j;
    int len=0;
    map<int,int> m;
    char *res=new char[j];
    if(k%j==0){
        return 0;
    }
    if(a/b){
        a=a%b;  //得到开始计算小数的分子
    }
    while(a%b && !m[a%b]){  //出现相同的余数即重复了
        if(len>b){
            break;
        }
        m[a%b]=len;
        a*=10;
        res[len++]=a/b+'0';
        a%=b;
    }
    res[len]='\0';
    cout<<"测试结果："<<res<<endl;
    cout<<"位置："<<m[a%b]<<endl;
    if(m[a%b]){
        return res+m[a%b];
    }
    else
        return 0;
}

//计算两个绝对路径的共同深度 eg. ~/a/b/c ~/a/d
unsigned get_common_depth(const char *path1,const char *path2){
    size_t len = strlen(path1)<strlen(path2)?strlen(path1):strlen(path2);
    size_t i,count=0;
    for(i=0;i<len;i++){
        //cout<<*(path1+i)<<" "<<*(path2+i)<<endl;
        if(*(path1+i)==*(path2+i)){
            //cout<<*(path1+i)<<endl;
            if(*(path1+i)=='/'){
                count++;
                //cout<<ount<<endl;
                continue;
            }
        }else{
            return count;
        }
    }
    return count+1;
}

int main(){
    unsigned a,b;
    char *path1=new char[1000];
    char *path2=new char[1000];
    //cin>>a>>b;
    //cout<<get_circle_digits(a,b)<<endl;
    cin>>path1>>path2;
    cout<<get_common_depth(path1,path2)<<endl;
    return 0;
}
