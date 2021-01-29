#include<iostream>

using namespace std;

int n;
bool num[10001];

int main()
{
	for(int i=2;i<=10000;i++){
		num[i]=true;
	}
	for(int i=2;i<=10000;i++){
		for(int j=2;j<i;j++){
			if(i%j==0)num[i]=false;
		}
	}
	cin>>n;
	for(int i=4;i<=n;i+=2){
		for(int j=2;j<=n;j++){
			if(num[j]&&num[i-j]){
				cout<<i<<'='<<j<<'+'<<i-j<<endl;
				break;
			}
		}
	}
	return 0;
}