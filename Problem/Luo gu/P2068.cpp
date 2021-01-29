#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long

using namespace std;

const LL Maxn=1e6+5;
LL N,M,X,Y,Tree[Maxn];
char Flag;

LL Lowbit(LL X){return X&(-X);}
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
LL GetSum(LL L,LL R)
{
    return Profix(R)-Profix(L-1);
}
int main()
{
    cin>>N>>M;
    for(LL i=1;i<=M;i++){
        cin>>Flag>>X>>Y;
        if(Flag=='x'){
            UpDate(X,Y);
        }else{
            printf("%lld\n",GetSum(X,Y));
        }
    }
    return 0;
}