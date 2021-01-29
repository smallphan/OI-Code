#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int Maxn=1000005;
struct Node{
    int Next,End;
}Edge[Maxn];
int From,To;
int First[Maxn],Len;
int Depth[Maxn],Up[Maxn][25];
int N,M,S;
int x,y;

inline int Read()
{
	int Ans=0,Flag=1;char X=getchar();
	while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
	while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
	return Ans*Flag;
}
void AddEdge(int Start,int End)
{
    Edge[++Len].Next=First[Start];
    First[Start]=Len;
    Edge[Len].End=End;
}
void DFS(int Start,int Father)
{
    Up[Start][0]=Father;
    Depth[Start]=Depth[Father]+1;
    for(int i=First[Start];i!=-1;i=Edge[i].Next){
        if(Edge[i].End!=Father){
            DFS(Edge[i].End,Start);
        }
    }
}
void Init()
{    
    for(int k=1;(1<<k)<=N;k++){
        for(int i=1;i<=N;i++){
            Up[i][k]=Up[Up[i][k-1]][k-1];
        }
    }
}
int LCA(int One,int Two)
{
    if(Depth[One]<Depth[Two]){
        swap(One,Two);
    }
    if(Depth[One]!=Depth[Two]){
        for(int k=20;k>=0;k--){
            if(Depth[Up[One][k]]>=Depth[Two]){
                One=Up[One][k];
            }
        }
    }
    if(One==Two){
        return One;
    }
    for(int k=20;k>=0;k--){
        if(Up[One][k]!=Up[Two][k]){
            One=Up[One][k];
            Two=Up[Two][k];
        }
    }
    return Up[One][0];
}
int main()
{
    memset(First,-1,sizeof(First));
    N=Read(),M=Read(),S=Read();
    for(int i=1;i<=N-1;i++){
        From=Read(),To=Read();
        AddEdge(From,To);
        AddEdge(To,From);
    }
    DFS(S,0);
    Init();
    while(M--){
        x=Read(),y=Read();
        cout<<LCA(x,y)<<endl;
    }
    return 0;
}