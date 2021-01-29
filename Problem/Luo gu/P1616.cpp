#include<iostream>
#include<algorithm>

using namespace std;

int T,M,Time[1000005],Value[1000005];
int DP[1000005],Ans;

int main()
{
	cin>>T>>M;
	for(int i=1;i<=M;i++){
		cin>>Time[i]>>Value[i];
	}	
	for(int i=1;i<=M;i++){
		for(int j=Time[i];j<=T;j++){
			DP[j]=max(DP[j],DP[j-Time[i]]+Value[i]);
		}
	}
	for(int i=1;i<=T;i++){
		Ans=max(Ans,DP[i]);
	}
	cout<<Ans<<endl;
	return 0;
}