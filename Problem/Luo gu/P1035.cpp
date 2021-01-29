#include<iostream>

using namespace std;

int main()
{
	long double s=1,sum=0,k;
	cin>>k;
	while(sum<=k){
		sum+=(double)1/s;
		s++;
	}
	cout<<s-1<<endl;
	return 0;
}