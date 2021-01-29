#include<iostream>
#include<iomanip>
using namespace std;

double sum;
int n;

int main()
{
	cin>>n;
	if(n<=150)sum=n*0.4463;
	else if(n<=400)sum=150*0.4463+(n-150)*0.4663;
	else sum=150*0.4463+250*0.4663+(n-400)*0.5663;
	cout<<fixed<<setprecision(1)<<sum;
	return 0;
}