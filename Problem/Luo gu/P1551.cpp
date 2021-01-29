#include<iostream>

using namespace std;

const int Maxn=5050;
int n,m,p,x,y;
int Father[Maxn];

int Find(int X)
{
	if(Father[X]==X)return X;
	else return Father[X]=Find(Father[X]);
}
void Merge(int A,int B)
{
	A=Find(A),B=Find(B);
	if(A!=B)Father[A]=B;
	return;
}
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)Father[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		Merge(x,y);
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		if(Find(x)==Find(y)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
} 