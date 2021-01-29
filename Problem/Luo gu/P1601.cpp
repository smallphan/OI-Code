#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

char x[510]={0},y[510]={0};
int m,n,t,a[510]={0},b[510]={0},c[510]={0};
int i;

int main()
{	
	cin>>x>>y;
	m=strlen(x);
	n=strlen(y);
	for(i=m;i>=1;i--){
		a[i]=x[m-i]-48;
	}
	for(i=n;i>=1;i--){
		b[i]=y[n-i]-48;
	}
	if(m<n){
		swap(m,n);
	}
	for(i=1;i<=m;i++){
		c[i]=a[i]+b[i];
	}
	for(i=1;i<=m;i++){
		if(c[i]>=10){
			c[i]=c[i]%10;
			c[i+1]=c[i+1]+1;
			if(i==m)m++;
		}
	}
	for(i=m;i>=1;i--){
		cout<<c[i];
	}
	cout<<endl;
	return 0;
} 