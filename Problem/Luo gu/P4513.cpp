#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=5e5+5;
struct node{
    int l,r;
    int maxL,maxR,sum,maxNum;
}tree[maxn<<2];
int n,m,opt,a,b;

inline int read();
void init(int,int);
void pushUp(int);
void build(int,int,int);
void modify(int,int,int);
node query(int,int,int);

int main(){
    n=read(),m=read();
    build(1,1,n);
    while(m--){
        opt=read();
        if(opt==1){
            a=read(),b=read();
            if(a>b) swap(a,b);
            node ans=query(1,a,b);
            printf("%d\n",ans.maxNum);
        }else{
            a=read(),b=read();
            modify(1,a,b);
        }
    }
    return 0;
}

inline int read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void pushUp(int point){
    tree[point].sum=tree[lSon].sum+tree[rSon].sum;
    tree[point].maxL=max(tree[lSon].maxL,tree[lSon].sum+tree[rSon].maxL);
    tree[point].maxR=max(tree[rSon].maxR,tree[rSon].sum+tree[lSon].maxR);
    tree[point].maxNum=max(max(tree[lSon].maxNum,tree[rSon].maxNum),tree[lSon].maxR+tree[rSon].maxL);
}
void init(int point,int key){
    tree[point].maxL=tree[point].maxR=tree[point].sum=tree[point].maxNum=key;
}
void build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        init(point,read());
    }else{
        int mid=(l+r)>>1;
        build(lSon,l,mid);
        build(rSon,mid+1,r);
        pushUp(point);
    }
}
void modify(int point,int pos,int key){
    if(tree[point].l==tree[point].r){
        init(point,key);
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(pos<=mid) modify(lSon,pos,key);
        else modify(rSon,pos,key);
        pushUp(point);
    }
}
node query(int point,int l,int r){
    if(l<=tree[point].l && r>=tree[point].r){
        return tree[point];
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(r<=mid) return query(lSon,l,r);
        else if(l>mid) return query(rSon,l,r);
        else{
            node lTree=query(lSon,l,r),rTree=query(rSon,l,r),ans;
            ans.sum=lTree.sum+rTree.sum;
            ans.maxL=max(lTree.maxL,lTree.sum+rTree.maxL);
            ans.maxR=max(rTree.maxR,rTree.sum+lTree.maxR);
            ans.maxNum=max(max(lTree.maxNum,rTree.maxNum),lTree.maxR+rTree.maxL);
            return ans;
        }
    }
}