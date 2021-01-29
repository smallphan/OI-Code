#include<iostream>

using namespace std;

int n,i=1;

int main()
{
	cin>>n;
	while(1)
	{
		if(i*i>n){
			break;
		}
		cout<<i*i<<' ';
		i++;
	}
	return 0;
} 