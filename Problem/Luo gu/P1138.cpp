#include<iostream>
#include<algorithm>

using namespace std;

int num[10001];
int n,k;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);    
	int ans=unique(num+1,num+n+1)-num;
	if(k<ans){
		cout<<num[k];
	}
	else cout<<"NO RESULT";
	return 0;
}