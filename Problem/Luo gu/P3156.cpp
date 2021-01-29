#include <iostream>
#include<cstdio>
#define LL long long

using namespace std;

const LL Maxn=2e6+5;
LL Num[Maxn];
LL N,M;

inline LL Read()
{
    LL Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    N=Read(),M=Read();
    for(LL i=1;i<=N;i++)Num[i]=Read();
    while(M--){
        printf("%d\n",Num[Read()]);
    }
    return 0;
}