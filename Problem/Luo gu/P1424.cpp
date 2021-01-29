#include<iostream>

using namespace std;

int n,x,a;
long long sum;

int main()
{
	cin>>x>>n;
	for(int i=x;i<=n+x-1;i++){
		a=i%7;
		a=a==0?7:a;
		if(a!=6&&a!=7)sum++;
	}
	sum*=250;
	cout<<sum;
	return 0;
}