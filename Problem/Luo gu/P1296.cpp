#include<iostream>
#include<algorithm>

using namespace std;

int n,d,ans;
int cow[1000001];

int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>cow[i];
	}
	sort(cow+1,cow+1+n);
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(cow[j]-cow[i]<=d){
				ans++;
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}