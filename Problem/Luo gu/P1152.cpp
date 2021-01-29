#include<iostream>
#include<algorithm>

using namespace std;

long n,jdzz[1001],num[1001];
 
int jdz(int x)
{
	if(x<0)return -x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>jdzz[i];
		if(i>=2){
			num[i-1]=jdz(jdzz[i]-jdzz[i-1]);
		}
	}
	sort(num+1,num+n);
	for(int i=1;i<=n-1;i++){
		if(num[i]!=i){
			cout<<"Not jolly"<<endl;
			return 0;
		}
	}
	cout<<"Jolly"<<endl;
	return 0;
}