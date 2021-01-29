#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<iostream>

using namespace std;

const int Maxn=40005;
int N,W;//N宝物种类 W最大载重 
int Ans,Cnt;
int Value[Maxn],Weight[Maxn],Num[Maxn];
int Value_,Weight_,Num_;
int F[Maxn];

int main()
{
	cin>>N>>W;
	for(int i=1;i<=N;i++){
		cin>>Value_>>Weight_>>Num_;
		for(int j=1;j<=Num_;j*=2){
			Num_-=j;
			Value[++Cnt]=j*Value_;
			Weight[Cnt]=j*Weight_;
		}
		if(Num_){
			Value[++Cnt]=Num_*Value_;
			Weight[Cnt]=Num_*Weight_;			
		}
	}
	N=Cnt;
	for(int i=1;i<=N;i++){
		for(int j=W;j>=Weight[i];j--){
			F[j]=max(F[j],F[j-Weight[i]]+Value[i]);
		}
	}
	cout<<F[W]<<endl;
	return 0;
}