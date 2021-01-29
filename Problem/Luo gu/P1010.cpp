#include<iostream>

using namespace std;

int num[16],n;

void ans(int n)
{
	int a=n;
	for(int i=14;i>=0;i--){
		if(num[i]<=a){
			a-=num[i];
			if(i!=1&&i!=0){
				cout<<"2(";
				ans(i);
				if(a==0){
					cout<<")";
				}
				else cout<<")+";
			}
			else if(i==1){
				if(a==0){
					cout<<'2';
				}
				else cout<<"2+";
			}
			else if(i==0){
				cout<<"2(0)";
			}
		}
	}
}
int main()
{
	num[0]=1;
	for(int i=1;i<=14;i++){
		num[i]=num[i-1]*2;
	}
 	cin>>n;
	ans(n);
}