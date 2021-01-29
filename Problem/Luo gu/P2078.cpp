#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int Maxn=10005;
int N,M,P,Q;
int A,B;
int FatherMale[Maxn],FatherFemale[Maxn];
int AnsMale,AnsFemale;

inline int Read()
{
	int Ans=0,Flag=1;char X=getchar();
	while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}	
	while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
	return Ans*Flag;
}
int FindMale(int X)
{
	if(X==FatherMale[X])return X;
	else return FatherMale[X]=FindMale(FatherMale[X]);
}
void MergeMale(int A,int B)
{
	A=FindMale(A),B=FindMale(B);
	if(A!=B)FatherMale[A]=B;
}
int FindFemale(int X)
{
	if(X==FatherFemale[X])return X;
	else return FatherFemale[X]=FindFemale(FatherFemale[X]);
}
void MergeFemale(int A,int B)
{
	A=FindFemale(A),B=FindFemale(B);
	if(A!=B)FatherFemale[A]=B;
}
int main()
{
	N=Read(),M=Read(),P=Read(),Q=Read();
	for(int i=1;i<=max(N,M);i++){
		FatherMale[i]=FatherFemale[i]=i;	
	}
	for(int i=1;i<=P;i++){
		A=Read(),B=Read();
		MergeMale(A,B);
	}	
	for(int i=1;i<=Q;i++){
		A=Read(),B=Read();
		A=-A,B=-B;
		MergeFemale(A,B);
	}
	for(int i=1;i<=N;i++){
		if(FindMale(i)==FindMale(1))AnsMale++;
	}
	for(int i=1;i<=M;i++){
		if(FindFemale(i)==FindFemale(1))AnsFemale++;
	}
	cout<<min(AnsMale,AnsFemale)<<endl;
	return 0;
}