#include<iostream>
#include<algorithm>

using namespace std;

string num[21];
int n;
string a;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(num[i]+num[j]<num[j]+num[i]){
				swap(num[i],num[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<num[i];
	}
	return 0;
}