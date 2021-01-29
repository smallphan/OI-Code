#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char x[10],y[10];
int sumx=1,sumy=1;

int main()
{
	gets(x);gets(y);
	for(int i=0;i<strlen(x);i++){
		sumx*=(int)(x[i]-64);
	}
	sumx=sumx%47;
	for(int i=0;i<strlen(y);i++){
		sumy*=(int)(y[i]-64);
	}
	sumy=sumy%47;
	if(sumx==sumy)cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}