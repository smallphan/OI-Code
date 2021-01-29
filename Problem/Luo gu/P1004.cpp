#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn=15;
int N,X,Y,Z,Num[Maxn][Maxn];
int DP[Maxn][Maxn][Maxn][Maxn];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    N=Read();
    while(cin>>X>>Y>>Z&&(X||Y||Z)){
        Num[X][Y]=Z;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                for(int l=1;l<=N;l++){
                    DP[i][j][k][l]=max(max(DP[i-1][j][k-1][l],DP[i-1][j][k][l-1]),max(DP[i][j-1][k-1][l],DP[i][j-1][k][l-1]))+Num[i][j]+Num[k][l];
                    if(i==k&&j==l)DP[i][j][k][l]-=Num[i][j];
                }
            }
        }
    }
    printf("%d\n",DP[N][N][N][N]);
    return 0;
}