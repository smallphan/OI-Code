#include<iostream>

using namespace std;

struct per{
	int a;
	int x;
};
per person[21],add[21];
int a,n,m,x,go;//get_off
int fib[21];

int main()
{
	cin>>a>>n>>m>>x;
	fib[1]=fib[2]=1;
	for(int i=3;i<=20;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	person[1].a=1;
	add[1].a=1;
	add[3].a=1;
	for(int i=4;i<=20;i++){
		add[i].x=fib[i-3];
	}
	for(int i=5;i<=20;i++){
		add[i].a=fib[i-4];
	}
	for(int i=2;i<=20;i++){
		person[i].a=person[i-1].a+add[i].a;
		person[i].x=person[i-1].x+add[i].x;
	}
	go=(m-person[n-1].a*a)/person[n-1].x;
	cout<<person[x].a*a+person[x].x*go<<endl;
	return 0;
}