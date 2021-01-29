#include<map>
#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=1e3+5;
struct nodeI{
    int l,r;
}poster[maxn<<2];
struct nodeII{
    int l,r,tag;
}tree[maxn<<2];
int n,m,a,b,x[maxn<<2],cnt;
int wall[maxn],ans,flag;
bool vis[maxn];
map<int,int>fin;

inline int Read();
void PushDn(int);
void Build(int,int,int);
void Modify(int,int,int,int);
void Query(int);

int main(){
    vis[0]=true;
    n=Read(),m=Read();
    for(int i=1;i<=m;i++){
        poster[i].l=Read(),poster[i].r=Read()+1;
        x[++cnt]=poster[i].l,x[++cnt]=poster[i].r;
    }
    sort(x+1,x+1+(m<<1));
    int tot=unique(x+1,x+1+(m<<1))-x-1;
    for(int i=1;i<=tot;i++) fin[x[i]]=i;
    Build(1,1,tot-1);
    for(int i=1;i<=m;i++){
        Modify(1,fin[poster[i].l],fin[poster[i].r]-1,(++flag));
    }
    Query(1);
    for(int i=1;i<=tot-1;i++){
        if(!vis[wall[i]]){
            ans++;
            vis[wall[i]]=true;
        }
    }
    printf("%d\n",ans);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushDn(int point){
    if(tree[point].tag){
        tree[lSon].tag=tree[point].tag;
        tree[rSon].tag=tree[point].tag;
        tree[point].tag=0;
    }
}
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r) return;
    else{
        int mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
    }
}
void Modify(int point,int l,int r,int key){
    if(l<=tree[point].l && r>=tree[point].r){
        tree[point].tag=key;
    }else{
        PushDn(point);
        int mid=(tree[point].l+tree[point].r)>>1;
        if(l<=mid) Modify(lSon,l,r,key);
        if(r>=mid+1) Modify(rSon,l,r,key);
    }
}
void Query(int point){
    if(tree[point].l==tree[point].r){
        wall[tree[point].l]=tree[point].tag;
    }else{
        PushDn(point);
        Query(lSon);
        Query(rSon);
    }
}