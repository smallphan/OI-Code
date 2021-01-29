#include<iostream>

using namespace std;

int num[11];
int main()
{
	int high,sum=0;
	for(int i=1;i<=10;i++){
		cin>>num[i];
	}
	cin>>high;
	for(int i=1;i<=10;i++){
		if(num[i]<=high+30)
			sum++;
	}
	cout<<sum;
	return 0;
}