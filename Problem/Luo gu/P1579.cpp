#include<iostream>

using namespace std;

bool num[20001];
int n;

void start(int n)
{
	num[2]=true;
	for(int i=3;i<=n;i++){
		bool check=true;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				check=false;
				break;
			}
		}
		if(check)num[i]=true;
	} 
}
int main()
{
	cin>>n;
	start(n);
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(num[i]&&num[j]&&num[k]&&i+j+k==n){
					cout<<i<<' '<<j<<' '<<k<<endl;
					return 0;
				}
			}
		}
	}
}