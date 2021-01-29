#include<iostream>

using namespace std;

int n,m;
int ans;
int num;
int sum;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num;
		sum+=num;
		if(sum>m){
			sum=num;
			ans++;
		}
	}
	ans++;
	cout<<ans;
}