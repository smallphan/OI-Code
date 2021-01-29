#include<cmath>
#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
struct node{
    ll l,r,sum,max;
}tree[maxn<<2];
ll opt,n,m,a,b;

inline ll Read();
void PushUp(ll);
void PushDn(ll);
void Build(ll,ll,ll);
void Modify(ll,ll,ll);
ll Query(ll,ll,ll);

int main(){
    n=Read();
    Build(1,1,n);
    m=Read();
    while(m--){
        opt=Read(),a=Read(),b=Read();
        if(a>b) swap(a,b);
        if(opt){
            printf("%lld\n",Query(1,a,b));
        }else{
            Modify(1,a,b);
        }  
    }
}

inline ll Read(){
    ll ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushUp(ll point){
    tree[point].max=max(tree[lSon].max,tree[rSon].max);
    tree[point].sum=tree[lSon].sum+tree[rSon].sum;
}
void Build(ll point,ll l,ll r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        tree[point].max=tree[point].sum=Read();
    }else{
        ll mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);
    }
}
void Modify(ll point,ll l,ll r){
    if(tree[point].l==tree[point].r){
        tree[point].sum=sqrt(tree[point].sum);
        tree[point].max=sqrt(tree[point].max);
    }else{
        ll mid=(tree[point].l+tree[point].r)>>1;
        if(l<=mid && tree[lSon].max>1) Modify(lSon,l,r);
        if(r>=mid+1 && tree[rSon].max>1) Modify(rSon,l,r);
        PushUp(point);
    }
}
ll Query(ll point,ll l,ll r){
    if(l<=tree[point].l && r>=tree[point].r){
        return tree[point].sum;
    }else{
        ll mid=(tree[point].l+tree[point].r)>>1,ans=0;
        if(l<=mid) ans+=Query(lSon,l,r);
        if(r>=mid+1) ans+=Query(rSon,l,r);
        return ans;
    }
}