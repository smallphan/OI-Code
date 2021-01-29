#include<iostream>

using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int mins,mine,min;
	mins=a*60+b;
	mine=c*60+d;
	min=mine-mins;
	cout<<min/60<<' '<<min%60;
	return 0;
}