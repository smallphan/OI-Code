#include<iostream>
#include<algorithm>

using namespace std;

int num[10001],n;
int sum,t;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			if(num[i]>num[j]){
				swap(num[i],num[j]);
				sum++;
			}
		}
	}
	cout<<sum;
}