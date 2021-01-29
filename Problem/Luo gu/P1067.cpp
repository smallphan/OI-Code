#include<iostream>

using namespace std;

int n,num;

int main()
{
	cin>>n;
	for(int i=n;i>=0;i--){
		cin>>num;
		if(num>0){
			if(i==n){
				if(num!=1){
					cout<<num;
				}
				cout<<"x";
				if(i!=1)cout<<'^'<<i;
			}
			else if(i<n&&i>0){
				cout<<"+";
				if(num!=1){
					cout<<num;
				}
				cout<<"x";
				if(i!=1)cout<<'^'<<i;
			}
			else{
				cout<<"+"<<num;
			}
		}
		else if(num==0){
			continue;
		}
		else{
			if(i>0){
				if(num!=-1){
					cout<<num;
				}
				else{
					cout<<'-';
				}
				cout<<"x";
				if(i!=1)cout<<'^'<<i;
			}
			else{
				cout<<num;
			}
		}
	}
	return 0;
} 