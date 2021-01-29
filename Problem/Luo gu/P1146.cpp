#include<iostream>

using namespace std;

int num[101];

int main()
{
	int n;
	cin>>n;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<((i&1)^1);
		}
		for(int j=i+1;j<=n;j++){
			cout<<(i&1);
		}
		cout<<endl;
	}
	return 0;
}