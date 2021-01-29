#include<iostream>

using namespace std;

char num[15];
int ans,a=1;

int main()
{
	cin>>num;
	for(int i=0;i<=10;i++){
		if(i==1||i==5){
			continue;
		}
		ans+=(num[i]-48)*a;
		a++;
	}
	char x=ans%11!=10?ans%11+48:'X';
	if(x==num[12])cout<<"Right"<<endl;
	else{
		num[12]=x;
		cout<<num;
	}
	return 0;
}