#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int>v;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int nnn;
		cin >> nnn;
		v.push_back(nnn);
		//cin>>num[i];
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		cout<<v[i]<<' ';
	}
	return 0;
}