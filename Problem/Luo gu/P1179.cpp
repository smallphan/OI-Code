#include<iostream>

using namespace std;

int l,r;
int sum,num,a;

int main()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		num=i;
		while(num!=0){
			a=num%10;
			num/=10;
			if(a==2)sum++;
		}
	}
	cout<<sum;
	return 0;
}