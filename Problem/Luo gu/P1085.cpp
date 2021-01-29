#include<iostream>

using namespace std;

int main()
{
	int maxa=-1,t,x,y;
	for(int i=1;i<=7;i++){
		cin>>x>>y;
		if(maxa<x+y){
			maxa=x+y;
			t=i;
		}
	}
	cout<<t;
}