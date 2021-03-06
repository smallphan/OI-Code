#include<cstdio>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

typedef long long ll;
const ll maxn=1e6+5;
struct node{
    ll l,r,len,sum,tag;
}tree[maxn<<2];
ll opt,n,m,a,b,k,d;
ll num[maxn];

inline ll Read();
void PushUp(ll);
void PushDn(ll);
void Build(ll,ll,ll);
void Modify(ll,ll,ll,ll);
ll Query(ll,ll,ll);

//*****
int main(){
    n=Read(),m=Read();
    for(int i=1;i<=n;i++) num[i]=Read();
    Build(1,1,n);
    while(m--){
        opt=Read();
        if(opt==1){
            a=Read(),b=Read(),k=Read(),d=Read();
            Modify(1,a,a,k);
            if(b>a) Modify(1,a+1,b,d);
            if(b!=n) Modify(1,b+1,b+1,-(k+(b-a)*d));
        }else{
            a=Read();
            printf("%lld\n",Query(1,1,a));
        }
    }
    return 0;
}

inline ll Read(){
    ll ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushUp(ll point){
    tree[point].len=tree[lSon].len+tree[rSon].len;
    tree[point].sum=tree[lSon].sum+tree[rSon].sum;
}
void PushDn(ll point){
    if(tree[point].tag){
        tree[lSon].sum+=tree[lSon].len*tree[point].tag;
        tree[rSon].sum+=tree[rSon].len*tree[point].tag;
        tree[lSon].tag+=tree[point].tag;
        tree[rSon].tag+=tree[point].tag;
        tree[point].tag=0;
    }
}
void Build(ll point,ll l,ll r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        tree[point].len=1;
        tree[point].sum=num[l]-num[l-1];
    }else{
        ll mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);
    }
}
void Modify(ll point,ll l,ll r,ll key){
    if(l<=tree[point].l && r>=tree[point].r){
        tree[point].sum+=tree[point].len*key;
        tree[point].tag+=key;
    }else{
        PushDn(point);
        ll mid=(tree[point].l+tree[point].r)>>1;
        if(l<=mid) Modify(lSon,l,r,key);
        if(r>=mid+1) Modify(rSon,l,r,key);
        PushUp(point);
    }
}
ll Query(ll point,ll l,ll r){
    if(l<=tree[point].l && r>=tree[point].r){
        return tree[point].sum;
    }else{
        PushDn(point);
        ll mid=(tree[point].l+tree[point].r)>>1,ans=0;
        if(l<=mid) ans+=Query(lSon,l,r);
        if(r>=mid+1) ans+=Query(rSon,l,r);
        return ans;
    }
}