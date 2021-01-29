#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int i,j,ss[101]={0},a,b[27]={0},maxn=0,minn=100;
	char x[101]={};
	ss[0]=1;
	ss[1]=1;
	for(i=2;i<=100;i++){
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0){
				ss[i]=1;
			}
		}
	}
	cin>>x;
	for(i=0;i<strlen(x);i++){
		a=x[i];
		a=a-96;
		b[a]++;
	}
	for(i=1;i<=26;i++){
		if(maxn<b[i])maxn=b[i];
		if(minn>b[i]&&b[i]!=0)minn=b[i];
	}
	if(ss[maxn-minn]==0){
		cout<<"Lucky Word"<<endl<<maxn-minn;
	}	
	else{
		cout<<"No Answer"<<endl<<"0";
	}
	return 0;
}