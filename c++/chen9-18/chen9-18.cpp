#include <iostream>
#include <string.h>
using namespace std;

char *stringFilter(char *str){
	int len = strlen(str);
	char *q = (char*)malloc(sizeof(char)*(len+10));
	memset(q,0,sizeof(char)*(len+10));
	char *p=str;
	int state = 1;
	int j=0;
	for(int i=0;i<len;i++){
		if(state==1 && *p!='a' && *p!='b'){
			*q=*p;
			q++;
			j++;
		}
		if(state==2 && *p!='c'){
			*q='a';
			q++;
			j++;
			if(*p!='a' && *p!='b'){
				*q=*p;
				q++;
				j++;
			}
		}
		state=*p=='a'?2:1;
		if(j>1 && *(q-1)=='c' && *(q-2)=='a'){
			j=j-2;
			q-=2;
			*q='\0';
		}
		p++;
	}
	return q-j;
}

int main(){
	char str[]="aaccac";
	cout<<stringFilter(str)<<endl;
	return 0;
}