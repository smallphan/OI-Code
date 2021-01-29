#include<iostream>

using namespace std;

int n;
double a,t;
bool light[2000001];
int sum;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>t;
		sum=0;
		for(int j=1;j<=t;j++){
			sum=a*j;
			light[sum]=!light[sum];
		}
	}
	for(int i=1;i<=2000000;i++){
		if(light[i]){
			cout<<i;
			return 0;
		}
	}
}