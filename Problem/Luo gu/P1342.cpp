#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

#define LL long long
#define Lson (Point<<1)
#define Rson (Point<<1|1)
#define Dad (Point>>1)

using namespace std;

const LL INF=0x7fffffff;
const LL Maxn=1e6+5;
const LL Maxm=1e6+5;
struct NodeI{
    LL Dis,Point;
}Heap[Maxn<<1];
LL Size;
struct NodeII{
    LL End,Next,Value;
}EdgeI[Maxm<<1],EdgeII[Maxm<<1];
LL FirstI[Maxn],CntI;
LL FirstII[Maxn],CntII;
bool Vis[Maxn];
LL N,M,A,B,C,Ans,Dis[Maxn];

inline LL Read()
{
    LL Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void AddEdgeI(LL Start,LL End,LL Value)
{
    EdgeI[++CntI]=(NodeII){End,FirstI[Start],Value};
    FirstI[Start]=CntI;
}
void AddEdgeII(LL Start,LL End,LL Value)
{
    EdgeII[++CntII]=(NodeII){End,FirstII[Start],Value};
    FirstII[Start]=CntII;
}
void ShiftUp(LL Point);
void ShiftDn(LL Point);
bool Empty()
{
    return !Size;
}
LL Pop()
{
    LL RET=Heap[1].Point;
    Heap[1]=Heap[Size--];
    ShiftDn(1);
    return RET;
}
void Push(LL Dis,LL Point)
{
    Heap[++Size].Dis=Dis;
    Heap[Size].Point=Point;
    ShiftUp(Size);
}
void ShiftUp(LL Point)
{
    if(Point==1)return;
    if(Heap[Point].Dis<Heap[Dad].Dis){
        swap(Heap[Point],Heap[Dad]);
        ShiftUp(Dad);
    }
}
void ShiftDn(LL Point)
{
    LL Mark=Point;
    if(Lson<=Size&&Heap[Lson].Dis<Heap[Mark].Dis)Mark=Lson;
    if(Rson<=Size&&Heap[Rson].Dis<Heap[Mark].Dis)Mark=Rson;
    if(Mark==Point)return;
    swap(Heap[Mark],Heap[Point]);
    ShiftDn(Mark);
}
void DijkstraI(LL Start)
{
    for(LL i=1;i<=N;i++)Dis[i]=INF;
    Dis[Start]=0;
    Push(0,Start);
    while(!Empty()){
        LL k=Pop();
        if(Vis[k])continue;
        Vis[k]=true;
        for(LL j=FirstI[k];j!=-1;j=EdgeI[j].Next){
            LL To=EdgeI[j].End;
            if(Dis[To]-EdgeI[j].Value>Dis[k]){
                Dis[To]=Dis[k]+EdgeI[j].Value;
                if(!Vis[To]){
                    Push(Dis[To],To);
                }
            }
        }
    }
}
void DijkstraII(LL Start)
{
    for(LL i=1;i<=N;i++)Dis[i]=INF;
    Dis[Start]=0;
    Push(0,Start);
    while(!Empty()){
        LL k=Pop();
        if(Vis[k])continue;
        Vis[k]=true;
        for(LL j=FirstII[k];j!=-1;j=EdgeII[j].Next){
            LL To=EdgeII[j].End;
            if(Dis[To]-EdgeII[j].Value>Dis[k]){
                Dis[To]=Dis[k]+EdgeII[j].Value;
                if(!Vis[To]){
                    Push(Dis[To],To);
                }
            }
        }
    }
}
int main()
{
    memset(FirstI,-1,sizeof(FirstI));
    memset(FirstII,-1,sizeof(FirstII));
    N=Read(),M=Read();
    for(LL i=1;i<=M;i++){
        A=Read(),B=Read(),C=Read();
        AddEdgeI(A,B,C),AddEdgeII(B,A,C);
    }
    DijkstraI(1);
    for(LL i=2;i<=N;i++)Ans+=Dis[i];
    memset(Vis,0,sizeof(Vis));
    DijkstraII(1);
    for(LL i=2;i<=N;i++)Ans+=Dis[i];
    printf("%lld\n",Ans);
    return 0;
}