#include<iostream>

using namespace std;

int n,k,sum,num,ans,a[10001];

bool check(int x)
{
	if(x<2)return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
void DFS(int x)
{
	if(num>k)return;
	if(x==n+1){
		if(num<k)return;
		if(check(sum))ans++;
		return;
	}
	DFS(x+1);
	
	sum+=a[x];num++;
	DFS(x+1);
	sum-=a[x];num--;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	DFS(1);
	cout<<ans;
}