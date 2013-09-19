#include <iostream>
#include <string.h>
using namespace std;

int * multiple(int *firstNum,int *secondNum,int firstLen,int secondLen){
	int i,j;
	int *res=(int*)malloc(sizeof(int)*(firstLen+secondLen+10));
	memset(res,0,sizeof(int)*(firstLen+secondLen+10));
	for(i=0;i<firstLen;i++){
		for(j=0;j<secondLen;j++){
			res[i+j]+=firstNum[i]*secondNum[j];
		}
	}
	for(i=0;i<=(firstLen+secondLen-2);i++){
		res[i+1]+=res[i]/10;
		res[i]%=10;
	}
	return res;
}

int *reverse(int *arr,int length){
	int temp;
	for(int i=0;i*2<length;i++){
		temp=arr[i];
		arr[i]=arr[length-i-1];
		arr[length-i-1]=temp;
	}
	return arr;
}

int main(){
	int i;
	int a[3]={0,0,1};
	int *aa=reverse(a,3);
	for(i=0;i<3;i++){
		cout<<aa[i];
	}
	cout<<endl;
	int b[2]={1,2};
	int *bb=reverse(b,2);
	int *res=multiple(aa,bb,3,2);
	for(i=0;i<4;i++){
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}