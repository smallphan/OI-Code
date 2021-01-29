#include<iostream>

using namespace std;

long long num[101];
int i=1,a;

int main()
{
	while(1){
		cin>>a;
		if(a==0)break;
		num[i]=a;
		i++;
	}
	i--;
	for(int j=i;j>=1;j--){
		cout<<num[j]<<' ';
	}
	return 0;
}