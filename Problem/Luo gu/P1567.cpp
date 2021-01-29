#include<iostream>

using namespace std;

int n,a,b,sum,ans;

int main()
{
	cin>>n>>b;
	for(int i=2;i<=n;i++){
		cin>>a;
		if(a>b)sum++;
		else sum=0;
		b=a;
		ans=ans>sum?ans:sum;
	}
	cout<<++ans;
} 