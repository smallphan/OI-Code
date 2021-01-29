#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char num[20];
int len,sign;

int main()
{
	gets(num);
	len=strlen(num);
	if(num[0]=='-'){
		len--;
		while(num[len]=='0'){
			len--;
		}
		cout<<'-';
		for(int i=len;i>=1;i--){
			cout<<num[i];
		}
	}
	else{
		len--;
		while(num[len]=='0'){
			len--;
		}
		for(int i=len;i>=0;i--){
			cout<<num[i];
		}
	}
}