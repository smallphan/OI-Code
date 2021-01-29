#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=1e6+5;
struct node{
    int l,r;
    int beauty,price;
}tree[maxn<<2];
int opt,w,c;

inline int read();
void clear(int);
void pushUp(int);
void build(int,int,int);
void modify(int,int,int,int);
void delet(int,bool);

int main(){
    build(1,1,maxn);
    while(true){
        opt=read();
        if(opt==-1)break;
        switch(opt){
            case 1:
                w=read(),c=read();
                modify(1,w,c,c);
                break;
            case 2:
                delet(1,1);
                break;
            case 3:
                delet(1,0);
                break;
        }
    }
    printf("%d %d\n",tree[1].beauty,tree[1].price);
    return 0;
}

inline int read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void clear(int point){
    tree[point].beauty=tree[point].price=0;
}
void pushUp(int point){
    tree[point].beauty=tree[lSon].beauty+tree[rSon].beauty;
    tree[point].price=tree[lSon].price+tree[rSon].price;
}
void build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r) return;
    else{
        int mid=(l+r)>>1;
        build(lSon,l,mid);
        build(rSon,mid+1,r);
    }
}
void modify(int point,int beauty,int price,int pos){
    if(tree[point].l==tree[point].r){
        if(!tree[point].price) tree[point].beauty=beauty,tree[point].price=price;
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(pos<=mid) modify(lSon,beauty,price,pos);
        else modify(rSon,beauty,price,pos);
        pushUp(point);
    }
}
void delet(int point,bool flag){
    if(tree[point].l==tree[point].r){
        clear(point);
    }else{
        if(flag && tree[lSon].price && tree[rSon].price) delet(rSon,flag);
        else if(!tree[lSon].price) delet(rSon,flag);
        else delet(lSon,flag);
        pushUp(point);
    }
}