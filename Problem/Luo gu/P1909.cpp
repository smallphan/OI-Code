#include<iostream>

using namespace std;

int n;
int a[4],b[4];
int sum,x=10000000;

int main()
{
	cin>>n;
	for(int i=1;i<=3;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=3;i++){
		sum=n%a[i]==0?n/a[i]:n/a[i]+1;
		sum*=b[i];
		x=sum>x?x:sum;
	}
	cout<<x;
	return 0;
}