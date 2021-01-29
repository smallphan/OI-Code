#include<iostream>
#include<cstdio>
#define LL long long

using namespace std;

const LL Maxn=5e5+5;
LL N,M,Num[Maxn],Tree[Maxn];
LL Flag,A,B,C;

inline LL Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
inline LL Lowbit(LL X){return X&(-X);}
void UpDate(LL X,LL Data)
{
    for(LL i=X;i<=N;i+=Lowbit(i)){
        Tree[i]+=Data;
    }
}
LL Profix(LL X)
{
    LL Ans=0;
    for(LL i=X;i!=0;i-=Lowbit(i)){
        Ans+=Tree[i];
    }
    return Ans;
}
int main()
{
    N=Read(),M=Read();
    for(LL i=1;i<=N;i++){
        Num[i]=Read();
        UpDate(i,Num[i]-Num[i-1]);
    }
    while(M--){
        Flag=Read();
        if(Flag==1){
            A=Read(),B=Read(),C=Read();
            UpDate(A,C);
            UpDate(B+1,-C);
        }else{
            A=Read();
            printf("%lld\n",Profix(A));
        }
    }
    return 0;
}