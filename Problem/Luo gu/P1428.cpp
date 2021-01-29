#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,z;
	int a[101]={0},b[101]={0};
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		z=0;
		for(j=i-1;j>=1;j--){
			if(a[j]<a[i]){
				z++;
			}
		}
		b[i]=z;
	}
	for(i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 