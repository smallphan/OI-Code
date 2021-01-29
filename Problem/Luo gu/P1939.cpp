#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long 

using namespace std;

const int Mod=1e9+7;
const int Max=105;
struct Matrix{
    LL Data[Max][Max];
    void Init(){
        memset(Data,0,sizeof(Data));
    }
}Find,Num;
int T,K;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
Matrix Mul(Matrix A,Matrix B,int N,int M,int R)
{
    Matrix C;
    C.Init();
    for(int k=1;k<=M;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=R;j++){
                C.Data[i][j]=(C.Data[i][j]+(A.Data[i][k]*B.Data[k][j])%Mod)%Mod;
            }
        }
    }
    return C;
}
Matrix Pow(Matrix A,int N,int K)
{
    Matrix B;
    B.Init();
    for(int i=1;i<=N;i++)B.Data[i][i]=1;
    while(K){
        if(K&1)B=Mul(B,A,N,N,N);
        K>>=1;
        A=Mul(A,A,N,N,N);
    }
    return B;
}
int main()
{
    T=Read();
    while(T--){
        //Init
        memset(Find.Data,0,sizeof(Find.Data));
        Find.Data[1][1]=1;
        Find.Data[1][3]=1;
        Find.Data[2][1]=1;
        Find.Data[3][2]=1;
        for(int i=1;i<=3;i++)Num.Data[i][1]=1;

        K=Read();
        if(K<=3){
            cout<<1<<endl;
            continue;
        }
        Find=Pow(Find,3,K-3);
        Find=Mul(Find,Num,3,3,1);
        cout<<Find.Data[1][1]<<endl;
    }
}
/*
    Num
    {
         a[x]
        a[x-1]
        a[x-2]
    }
    Find
    {
        1 0 1
        1 0 0
        0 1 0
    }
    Find×Num:
              a[x]
             a[x-1]
             a[x-2]
           ×
    1 0 1    a[x+1]
    1 0 0     a[x]
    0 1 0    a[x-1]
*/