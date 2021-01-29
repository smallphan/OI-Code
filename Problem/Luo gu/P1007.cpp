#include<iostream>

using namespace std;

int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int min(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	int l,n,x,maxt=-1,mint=-1;
	cin>>l>>n;
	if(n==0){
		cout<<'0'<<' '<<'0';
		return 0;
	}
	int i;
	for(i=1;i<=n;i++){
		cin>>x;
		maxt=max(maxt,max(x,l+1-x));
		mint=max(mint,min(x,l+1-x));
	}
	cout<<mint<<' '<<maxt;
	return 0; 
}