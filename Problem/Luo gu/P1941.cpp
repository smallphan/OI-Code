#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int INF=0x3f3f3f3f;
const int Maxn=1e4+5;
const int Maxm=2e3+5;
int N,M,K,A,B,C;
int X[Maxn],Y[Maxn],Low[Maxn],High[Maxn];
int DP[Maxn][Maxm],Ans=INF;
bool Flag[Maxn];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    memset(DP,INF,sizeof(DP));
    N=Read(),M=Read(),K=Read();
    for(int i=1;i<=N;i++){
        X[i]=Read(),Y[i]=Read();
        Low[i]=1,High[i]=M;
    }
    for(int i=1;i<=K;i++){
        A=Read(),B=Read(),C=Read();
        Flag[A]=true,Low[A]=B+1,High[A]=C-1;
    }
    for(int i=1;i<=M;i++){
        DP[0][i]=0;
    }
    for(int i=1;i<=N;i++){
        for(int j=X[i]+1;j<=X[i]+M;j++){
            DP[i][j]=min(DP[i-1][j-X[i]]+1,DP[i][j-X[i]]+1);
        }
        for(int j=M+1;j<=X[i]+M;j++){
            DP[i][M]=min(DP[i][M],DP[i][j]);
        }
        for(int j=1;j<=M-Y[i];j++){
            DP[i][j]=min(DP[i][j],DP[i-1][j+Y[i]]);
        }
        for(int j=1;j<Low[i];j++){
            DP[i][j]=INF;
        }
        for(int j=High[i]+1;j<=M;j++){
            DP[i][j]=INF;
        }
    }
    for(int i=1;i<=M;i++)Ans=min(Ans,DP[N][i]);
    if(Ans<INF){
        printf("1\n%d\n",Ans);
        return 0;
    }
    int i,j;
    for(i=N;i>=1;i--){
        for(j=1;j<=M;j++){
            if(DP[i][j]<INF)break;
        }
        if(j<=M)break;
    }
    Ans=0;
    for(j=1;j<=i;j++){
        if(Flag[j])Ans++;
    }
    printf("0\n%d\n",Ans);
    return 0;
}