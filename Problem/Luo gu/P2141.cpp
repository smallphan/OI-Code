#include<iostream>
#include<algorithm>

using namespace std;

int n,num[101],ans;

bool cmp(int a,int b)
{
	if(a>b)return true;
	else return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(num[j]+num[k]==num[i]&&num[j]!=num[k]){
					ans++;
					k=n+1;
					j=n;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}