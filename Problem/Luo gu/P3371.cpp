#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int INF=0x7fffffff;
const int Maxn=1e4+5;
const int Maxm=1e6+5;
struct Node{
    int End,Next,Value;
}Edge[Maxm];
int First[Maxn],Len;
int N,M,S,X,Y,Z;
int Dis[Maxn];
bool Vis[Maxn];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void AddEdge(int Start,int End,int Value)
{
    Edge[++Len].Next=First[Start];
    First[Start]=Len;
    Edge[Len].End=End;
    Edge[Len].Value=Value;
}
void Dijkstra(int Start)
{
    for(int i=1;i<=N;i++)Dis[i]=INF;
    Dis[Start]=0;
    for(int i=1;i<=N;i++){
        int Min=INF,k=0;
        for(int j=1;j<=N;j++){
            if(!Vis[j]&&Min>Dis[j]){
                Min=Dis[j];
                k=j;
            }
        }
        Vis[k]=true;
        for(int j=First[k];j!=-1;j=Edge[j].Next){
            if(!Vis[Edge[j].End]&&Dis[k]+Edge[j].Value<Dis[Edge[j].End]){
                Dis[Edge[j].End]=Dis[k]+Edge[j].Value;
            }
        }
    }
}
int main()
{
    memset(First,-1,sizeof(First));
    N=Read(),M=Read(),S=Read();
    for(int i=1;i<=M;i++){
        X=Read(),Y=Read(),Z=Read();
        AddEdge(X,Y,Z);
    }
    Dijkstra(S);
    for(int i=1;i<=N;i++){
        printf("%d ",Dis[i]);
    }
    return 0;
}