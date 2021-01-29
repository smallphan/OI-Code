#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn=5e5+5;
int N,M,Tree[Maxn];
int A,B,C;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
inline int Lowbit(int X){return X&(-X);}
void UpDate(int X,int Data)
{
    for(int i=X;i<=N;i+=Lowbit(i)){
        Tree[i]+=Data;
    }
}
int Profix(int X)
{   
    int Ans=0;
    for(int i=X;i!=0;i-=Lowbit(i)){
        Ans+=Tree[i];
    }
    return Ans;
}
int GetSum(int L,int R)
{
    return Profix(R)-Profix(L-1);
}
int main()
{
    N=Read(),M=Read();
    for(int i=1;i<=N;i++){
        A=Read();
        UpDate(i,A);
    }
    while(M--){
        A=Read(),B=Read(),C=Read();
        if(A==1){
            UpDate(B,C);
        }else{
            printf("%d\n",GetSum(B,C));
        }
    }
    return 0;
}