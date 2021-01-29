#include<map>
#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=1e5+5;
struct node{
    int l,r,len,num,sum,tag;
}tree[maxn<<2];
int n,k,step,pos,x[maxn],cnt=1,work[maxn];
char dir[2];
map<int,int>fin;

inline int Read();
void PushUp();
void PushDn();
void Build(int,int,int);
void Modify(int,int,int);
void Query(int);

//*****
int main(){
    n=Read(),k=Read();
    for(int i=1;i<=n;i++){
        step=Read();
        scanf("%s",&dir);
        if(dir[0]=='L') pos-=step;
        else pos+=step;
        x[++cnt]=pos;
        work[cnt]=pos;
    }
    sort(x+1,x+1+cnt);
    int tot=unique(x+1,x+1+cnt)-x-1;
    for(int i=1;i<=tot;i++) fin[x[i]]=i;
    Build(1,1,tot-1);
    for(int i=1;i<=cnt-1;i++){
        int a=fin[work[i]],b=fin[work[i+1]];
        if(a>b) swap(a,b);
        b--;
        Modify(1,a,b);
    }
    Query(1);
    printf("%d\n",tree[1].sum);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushUp(int point){
    tree[point].len=tree[lSon].len+tree[rSon].len;
    tree[point].num=tree[lSon].num+tree[rSon].num;
    tree[point].sum=tree[lSon].sum+tree[rSon].sum;
}
void PushDn(int point){
    if(tree[point].tag){
        tree[lSon].num+=(tree[lSon].r-tree[lSon].l+1)*tree[point].tag;
        tree[rSon].num+=(tree[rSon].r-tree[rSon].l+1)*tree[point].tag;
        tree[lSon].tag+=tree[point].tag;
        tree[rSon].tag+=tree[point].tag;
        tree[point].tag=0;
    }
}
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        tree[point].len=x[l+1]-x[l];
    }else{
        int mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);
    }
}
void Modify(int point,int l,int r){
    if(l<=tree[point].l && r>=tree[point].r){
        tree[point].num+=(tree[point].r-tree[point].l+1);
        tree[point].tag++;
    }else{
        PushDn(point);
        int mid=(tree[point].l+tree[point].r)>>1;
        if(l<=mid) Modify(lSon,l,r);
        if(r>=mid+1) Modify(rSon,l,r);
        PushUp(point);
    }
}
void Query(int point){
    if(tree[point].l==tree[point].r){
        if(tree[point].num>=k) tree[point].sum=tree[point].len;
    }else{
        PushDn(point);
        Query(lSon);
        Query(rSon);
        PushUp(point);
    }
}