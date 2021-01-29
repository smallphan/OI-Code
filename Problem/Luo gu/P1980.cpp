#include<iostream>

using namespace std;

int n,x,sum;

int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		int a=i;
		while(a!=0){
			int b=a%10;
			a/=10;
			if(b==x)sum++;
		}
	}
	cout<<sum;
	return 0;
}