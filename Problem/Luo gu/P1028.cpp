#include<iostream>

using namespace std;

int num[1001];
int sum,n;

int main()
{
	cin>>n;
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	num[1]=2;
	for(int i=2;i<=n;i++){
		sum=0;
		for(int j=1;j<=(i/2);j++){
			sum+=num[j];
		}	
		num[i]=sum;
	}
	cout<<num[n]<<endl;
	return 0;
}