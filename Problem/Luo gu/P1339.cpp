#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int INF=0x3f3f3f3f;
const int MAXN=2505;
const int MAXM=6205;
struct Node{
    int End,Next,Value;
}Edge[MAXM<<1];
int First[MAXN],Cnt,Dis[MAXN];
bool Vis[MAXN];
int N,M,S,T,A,B,C;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void AddEdge(int Start,int End,int Value)
{
    Edge[++Cnt].Next=First[Start];
    First[Start]=Cnt;
    Edge[Cnt].End=End;
    Edge[Cnt].Value=Value;
}
void Dijkstra(int Start)
{
    for(int i=1;i<=N;i++)Dis[i]=INF;
    Dis[Start]=0;
    for(int i=1;i<=N;i++){
        int Min=INF,k=0;
        for(int j=1;j<=N;j++){
            if(!Vis[j]&&Min>Dis[j]){
                Min=Dis[j],k=j;
            }
        }
        Vis[k]=true;
        for(int j=First[k];j!=-1;j=Edge[j].Next){
            if(!Vis[Edge[j].End]){
                Dis[Edge[j].End]=min(Dis[Edge[j].End],Dis[k]+Edge[j].Value);
            }
        }
    }
}
int main()
{
    memset(First,-1,sizeof(First));
    N=Read(),M=Read(),S=Read(),T=Read();
    for(int i=1;i<=M;i++){
        A=Read(),B=Read(),C=Read();
        AddEdge(A,B,C),AddEdge(B,A,C);
    }
    Dijkstra(S);
    printf("%d\n",Dis[T]);
    return 0;
}