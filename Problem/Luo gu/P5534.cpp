#include<iostream>

using namespace std;

long long a1,a2,n;
long long a_last,sum;

int main()
{
	cin>>a1>>a2>>n;
	if(n==2)cout<<a1+a2<<endl;
	a_last=a1+(n-1)*(a2-a1);
	sum=(a1+a_last)*n/2;
	cout<<sum<<endl;
	return 0;
}