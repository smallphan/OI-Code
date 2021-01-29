#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)
#define dad (point>>1)

using namespace std;

const int inf=0x7f7f7f7f;
const int maxn=1e3+5;
const int maxm=1e3+5;
struct nodeI{
    int price,point,limit;
}heap[maxm<<1];
int size;
struct nodeII{
    int end,next,price,limit;
}edge[maxm<<1];
int first[maxn],cnt;
int price[maxn],limit[maxm];
bool vis[maxn];
int n,m,a,b,c,ans;

inline int Read();
void AddEdge(int,int,int,int);
bool Empty();
void ShiftUp(int);
void ShiftDn(int);
int Pop();
void Push(int,int,int);
int Dijkstra(int);

//*****
int main(){
    memset(first,-1,sizeof(first));
    n=Read(),m=Read();
    for(int i=1;i<=m;i++){
        a=Read(),b=Read(),c=Read(),limit[i]=Read();
        AddEdge(a,b,c,limit[i]); AddEdge(b,a,c,limit[i]);
    }
    for(int i=1;i<=m;i++) ans=max(ans,limit[i]*1000000/Dijkstra(limit[i]));
    printf("%d\n",ans);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void AddEdge(int start,int end,int price,int limit){
    edge[++cnt]=(nodeII){end,first[start],price,limit};
    first[start]=cnt;
}
bool Empty(){
    return !size;
}
void ShiftUp(int point){
    if(point==1) return;
    if(heap[point].price<heap[dad].price){
        swap(heap[point],heap[dad]);
        ShiftUp(dad);
    }
}
void ShiftDn(int point){
    int mark=point;
    if(lSon<=size && heap[lSon].price<heap[mark].price) mark=lSon;
    if(rSon<=size && heap[rSon].price<heap[mark].price) mark=rSon;
    if(mark==point) return;
    swap(heap[mark],heap[point]);
    ShiftDn(mark);
} 
int Pop(){
    int ret=heap[1].point;
    heap[1]=heap[size--];
    ShiftDn(1);
    return ret;
}
void Push(int price,int point,int limit){
    heap[++size]=(nodeI){price,point,limit};
    ShiftUp(size);
}
int Dijkstra(int minLimit){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) price[i]=inf;
    price[1]=0;
    Push(0,1,minLimit);
    while(!Empty()){
        int point=Pop();
        if(vis[point]) continue;
        vis[point]=true;
        for(int i=first[point];i!=-1;i=edge[i].next){
            int to=edge[i].end;
            if(edge[i].limit>=minLimit && price[to]>price[point]+edge[i].price){
                price[to]=price[point]+edge[i].price;
                Push(price[to],to,minLimit);
            }
        }
    }
    return price[n];
}