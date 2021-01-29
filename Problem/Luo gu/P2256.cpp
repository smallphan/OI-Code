#include<iostream>

using namespace std;

const int Maxn=20005;
struct Node{
	string Name;
	int Num;
}Person[Maxn];
int N,M,K; 
int Father[Maxn];
string A,B;

int Find(int X)
{
	if(X==Father[X])return X;
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
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		Father[i]=i;
		Person[i].Num=i;
		cin>>Person[i].Name;
	}
	for(int i=1;i<=M;i++){
		cin>>A>>B;
		int PosA=0,PosB=0;
		for(int i=1;i<=N;i++){
			if(A==Person[i].Name)PosA=Person[i].Num;
			if(B==Person[i].Name)PosB=Person[i].Num;
			if(PosA&&PosB)break;
		}
		Merge(PosA,PosB);
	}
	cin>>K;
	for(int i=1;i<=K;i++){
		cin>>A>>B;
		int PosA=0,PosB=0;
		for(int i=1;i<=N;i++){
			if(A==Person[i].Name)PosA=Person[i].Num;
			if(B==Person[i].Name)PosB=Person[i].Num;
			if(PosA&&PosB)break;
		}
		if(Find(PosA)==Find(PosB)){
			cout<<"Yes."<<endl;
		}else{
			cout<<"No."<<endl;
		}
	}
	return 0;
}