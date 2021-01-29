#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int INF=0x3f3f3f3f;
const int Maxn=5005;
int N,M,A,B,C,Ans;
int Edge[Maxn][Maxn],Low[Maxn],Pos[Maxn];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void Prim(int Root,int &Ans)
{
    Ans=0;
    for(int i=1;i<=N;i++){
        Low[i]=Edge[Root][i],Pos[i]=Root;
    }
    Pos[Root]=0;
    for(int k=1;k<N;k++){
        int MinValue=INF,Point=0;
        for(int i=1;i<=N;i++){
            if(Pos[i]>0&&Low[i]<MinValue){
                MinValue=Low[i],Point=i;
            }
        }
        Pos[Point]=0,Ans+=MinValue;
        for(int i=1;i<=N;i++){
            if(Pos[i]>0&&Edge[Point][i]<Low[i]){
                Low[i]=Edge[Point][i],Pos[i]=Point;
            }
        }
    }
}
int main()
{
    N=Read(),M=Read();
    memset(Edge,INF,sizeof(Edge));
    for(int i=1;i<=M;i++){
        A=Read(),B=Read(),C=Read();
        Edge[A][B]=Edge[B][A]=min(Edge[A][B],C);
    }
    Prim(1,Ans);
    cout<<Ans<<endl;
    return 0;
}