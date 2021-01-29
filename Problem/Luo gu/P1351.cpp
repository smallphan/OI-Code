#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define LL long long

using namespace std;

const int Mod=10007;
const int Maxn=200005;
struct Node{
	int Next,End;
}Edge[2*Maxn];
int First[Maxn],Len;
int N,A,B,Value[Maxn];
LL SumAns,MaxAns=-1;

inline int Read()
{
	int Ans=0,Flag=1;char X=getchar();
	while(X<'0'||X>'9'){
		if(X=='-')Flag=-1;
		X=getchar();
	}	
	while(X>='0'&&X<='9'){
		Ans=Ans*10+X-'0';
		X=getchar();
	}
	return Ans*Flag;
}
void AddEdge(int Start,int End)
{
	Edge[++Len].Next=First[Start];
	First[Start]=Len;
	Edge[Len].End=End;
}
int main()
{
	memset(First,-1,sizeof(First));
	N=Read();
	for(int i=1;i<=N-1;i++){
		A=Read(),B=Read();
		AddEdge(A,B),AddEdge(B,A);
	}
	for(int i=1;i<=N;i++){
		Value[i]=Read();
	}
	for(int k=1;k<=N;k++){
		LL Ans=0,Sum=0,Max=-1;
		for(int i=First[k];i!=-1;i=Edge[i].Next){
			Ans+=Value[Edge[i].End]*Sum,Ans%=Mod;
			Sum+=Value[Edge[i].End],Sum%=Mod;
			MaxAns=max(MaxAns,Max*Value[Edge[i].End]);
			Max=max(Max,(long long)Value[Edge[i].End]);
		}
		SumAns+=Ans,SumAns%=Mod;
	}
	SumAns=(SumAns*2)%Mod;
	cout<<MaxAns<<' '<<SumAns<<endl;
	return 0;
} 
