#include<iostream>

using namespace std;

int money,cost[13],cunkuan;
double sum;

int main()
{	
	for(int i=1;i<=12;i++){
		cin>>cost[i];
	}
	for(int i=1;i<=12;i++){
		money+=300;
		money-=cost[i];
		if(money<0){
			cout<<'-'<<i<<endl;
			return 0;
		}
		if(money>=100){
			cunkuan+=(money/100)*100;
			money%=100;
		}
	}
	sum=money+cunkuan*1.2;
	cout<<sum<<endl;
	return 0;
}