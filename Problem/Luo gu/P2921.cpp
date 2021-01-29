#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1e5+5;
int n,to[maxn],point[maxn],ring[maxn],flag;
bool vis[maxn];

inline int Read();
int DFS(int,int);

int main(){
    n=Read();
    for(int i=1;i<=n;i++) to[i]=Read();
    for(int i=1;i<=n;i++) printf("%d\n",DFS(i,1));
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
int DFS(int now,int value){
    if(ring[now])return value-1+ring[now];
    if(vis[now]){
        ring[now]=value-point[now]; flag=now;
        return value-1;
    }
    vis[now]=true; point[now]=value;
    int ans=DFS(to[now],value+1);
    if(flag){
        if(now==flag) flag=0;
        else ring[now]=ring[flag];
    }else ring[now]=ring[to[now]]+1;
    vis[now]=false;
    return ans;
}