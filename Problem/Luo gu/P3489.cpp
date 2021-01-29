#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

#define Pair pair<int,int>
#define f first
#define s second

using namespace std;

const int inf=0x7f7f7f7f;
const int maxn=505;
const int maxm=6005;
const int bd=14;
struct node{
    int end,next,dis,bits;
}edge[maxm];
int first[maxn],cnt;
int bitOn[maxn];
int dis[maxn][1<<bd],ans=inf;
int n,m,p,k;
bool inq[maxn],vis[maxn][bd];

inline int Read();
void AddEdge(int,int,int,int);
void Dijkstra(int);

//*****
int main(){
    memset(first,-1,sizeof(first));
    n=Read(),m=Read(),p=Read(),k=Read();
    for(int i=1;i<=k;i++){
        int a,b; a=Read(),b=Read();
        for(int j=1;j<=b;j++){
            int c; c=Read();
            bitOn[a]|=1<<(c-1);
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,c,d,bit=0;
        a=Read(),b=Read(),c=Read(),d=Read();
        for(int j=1;j<=d;j++){
            int e; e=Read();
            bit|=1<<(e-1);
        }
        AddEdge(a,b,c,bit);
        AddEdge(b,a,c,bit);
    }
	Dijkstra(1);
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void AddEdge(int start,int end,int dis,int bits){
    edge[++cnt]=(node){end,first[start],dis,bits};
	first[start]=cnt;
}
void Dijkstra(int start){
    memset(dis,inf,sizeof(dis));
    dis[start][bitOn[start]]=0;
    priority_queue<pair<int,Pair> >heap;
    heap.push(make_pair(0,make_pair(start,bitOn[start])));
    while(!heap.empty()){
        int qf=heap.top().s.f,qs=heap.top().s.s,curr=heap.top().f; heap.pop();
        if(qf==n) {ans=min(ans,-curr); break;}
        for(int i=first[qf];i!=-1;i=edge[i].next){
            if((qs|edge[i].bits)!=qs)continue;
            int goes=qs|bitOn[edge[i].end];
            if(dis[edge[i].end][goes]>dis[qf][qs]+edge[i].dis){
                dis[edge[i].end][goes]=dis[qf][qs]+edge[i].dis;
                heap.push(make_pair((-dis[edge[i].end][goes]),make_pair(edge[i].end,goes)));
            }
        }
    }
    printf("%d\n",ans==inf?-1:ans);
}