#include<iostream>

using namespace std;

long long n,k,sum;

int main()
{
	cin>>n>>k;
	sum=n;
	while(n/k!=0){
		sum+=n/k;
		n=n%k+n/k;
	}
	cout<<sum;
	return 0;
}