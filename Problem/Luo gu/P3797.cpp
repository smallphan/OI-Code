#include<cstdio>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=2e5+5;
struct node{
    int l,r,sum,posL,posR;
    bool haveL,haveR,check;
}tree[maxn<<2];
int n,m,opt,a,b;
char str;

inline int Read();
void PushUp(int);
void Build(int,int,int);
void Modify(int,int,int);
int Query(int,int,int);

//*****
int main(){
    n=Read(),m=Read();
    Build(1,1,n);
    while(m--){
        opt=Read();
        if(opt==1){
            a=Read();
            str=getchar();
            switch(str){
                case 'X':
                    Modify(1,a,1);
                    break;
                case '(':
                    Modify(1,a,2);
                    break;
                case ')':
                    Modify(1,a,3);
                    break;
            }
        }else{
            a=Read(),b=Read();
            printf("%d\n",Query(1,a,b));
        }
    }
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushUp(int point){
    tree[point].check=(tree[lSon].check && tree[rSon].check);
    if(tree[lSon].haveL) tree[point].haveL=true,tree[point].posL=tree[lSon].posL;
    else if(tree[lSon].check && tree[rSon].haveL) tree[point].haveL=true,tree[point].posL=tree[rSon].posL;
    else tree[point].haveL=false,tree[point].posL=0;
    if(tree[rSon].haveR) tree[point].haveR=true,tree[point].posR=tree[rSon].posR;
    else if(tree[rSon].check && tree[lSon].haveR) tree[point].haveR=true,tree[point].posR=tree[lSon].posR;
    else tree[point].haveR=false,tree[point].posR=0;
    tree[point].sum=tree[lSon].sum+tree[rSon].sum+(tree[lSon].haveR &&tree[rSon].haveL);
}
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        tree[point].check=true;
        if(l==1){
            tree[point].check=false;
            tree[point].haveR=true;
            tree[point].posR=1;
        }
        if(l==n){
            tree[point].check=false;
            tree[point].haveL=true;
            tree[point].posL=n;
        }
    }else{
        int mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);
    }
}//[key] 1->'X' 2->'(' 3->')'
void Modify(int point,int pos,int key){
    if(tree[point].l==tree[point].r){
        switch(key){
            case 1:
                tree[point].check=true;
                tree[point].haveL=tree[point].haveR=false;
                tree[point].posL=tree[point].posR=0;
                break;
            case 2:
                tree[point].check=tree[point].haveL=false;
                tree[point].haveR=true;
                tree[point].posL=0,tree[point].posR=tree[point].l;
                break;
            case 3:
                tree[point].check=tree[point].haveR=false;
                tree[point].haveL=true;
                tree[point].posR=0,tree[point].posL=tree[point].l;
                break;
        }
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(pos<=mid) Modify(lSon,pos,key);
        else Modify(rSon,pos,key);
        PushUp(point);
    }
}
int Query(int point,int l,int r){
    if(l<=tree[point].l && r>=tree[point].r){
        return tree[point].sum;
    }else{
        int mid=(tree[point].l+tree[point].r)>>1,ans=0,flag=0;
        if(l<=mid) ans+=Query(lSon,l,r),flag++;
        if(r>=mid+1) ans+=Query(rSon,l,r),flag++;
        if(flag==2) ans+=(tree[lSon].haveR && l<=tree[lSon].posR && tree[rSon].haveL && r>=tree[rSon].posL);
        return ans;
    }
}