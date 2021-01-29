#include<iostream>

using namespace std;

double a;

int main()
{
	double b=2;
	int sum=0;
	cin>>a;
	while(1){
		a-=b;
		b=(double)b*98/100;
		sum++;
		if(a<=0){
			cout<<sum;
			return 0;
		}
	}
} 