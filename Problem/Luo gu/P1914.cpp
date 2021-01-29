#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int n;
char num[51];

int main()
{
	int a;
	cin>>n;
	n=n%26;
	cin>>num;
	for(int i=0;i<strlen(num);i++){
		a=num[i]+n;
		if(a>122)a=96+a-122;
		cout<<(char)a;
	} 
	return 0;
} 