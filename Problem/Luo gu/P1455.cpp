#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn=4e4+5;
const int Maxm=5e4+5;
int N,M,W,A,B;
int Price[Maxn],Value[Maxn],Father[Maxn];
int DP[Maxm];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int Find(int X)
{
    if(Father[X]==X)return X;
    else return Father[X]=Find(Father[X]);
}
void Merge(int A,int B)
{
    A=Find(A),B=Find(B);
    if(A!=B)Father[A]=B;
}
int main()
{
    N=Read(),M=Read(),W=Read();
    for(int i=1;i<=N;i++)Father[i]=i;
    for(int i=1;i<=N;i++){
        Price[i]=Read(),Value[i]=Read();
    }
    for(int i=1;i<=M;i++){
        A=Read(),B=Read();
        Merge(A,B);
    }
    for(int i=1;i<=N;i++){
        if(i!=Find(i)){
            Price[Find(i)]+=Price[i];
            Value[Find(i)]+=Value[i];
            Price[i]=Value[i]=0;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=W;j>=Price[i];j--){
            DP[j]=max(DP[j],DP[j-Price[i]]+Value[i]);
        }
    }
    printf("%d\n",DP[W]);
    return 0;
}