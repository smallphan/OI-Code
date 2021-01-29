#include<iostream>

using namespace std;

double jl;
int s,x;
double v=7;

int main()
{
	cin>>s>>x;
	while(jl<s-x){
		jl+=v;
		v=(double)v*0.98;
	}
	if(jl+v>s+x)cout<<'n';
	else cout<<'y';
	return 0;
}