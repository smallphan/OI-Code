#include<cstdio>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=1e5+5;
struct node{
    int l,r,sum[2];
    //0->start 1->end
}tree[maxn<<2];
int opt,n,m,a,b;

inline int Read();
void PushUp(int,int);
void Build(int,int,int);
void Modify(int,int,int);
int Query(int,int,int,int);

//*****
int main(){
    n=Read(),m=Read();
    Build(1,1,n);
    while(m--){
        opt=Read(),a=Read(),b=Read();
        if(opt==1){
            Modify(1,a,0);
            Modify(1,b,1);
        }else{
            printf("%d\n",Query(1,1,b,0)-Query(1,1,a-1,1));
        }
    }
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushUp(int point,int flag){
    tree[point].sum[flag]=tree[lSon].sum[flag]+tree[rSon].sum[flag];   
}
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    Build(lSon,l,mid);
    Build(rSon,mid+1,r);
}
void Modify(int point,int pos,int flag){
    if(tree[point].l==tree[point].r){
        tree[point].sum[flag]++;
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(pos<=mid) Modify(lSon,pos,flag);
        else Modify(rSon,pos,flag);
        PushUp(point,flag);
    }
}
int Query(int point,int l,int r,int flag){
    if(l<=tree[point].l && r>=tree[point].r){
        return tree[point].sum[flag];
    }else{
        int mid=(tree[point].l+tree[point].r)>>1,ans=0;
        if(l<=mid) ans+=Query(lSon,l,r,flag);
        if(r>=mid+1) ans+=Query(rSon,l,r,flag);
        return ans;
    }
}