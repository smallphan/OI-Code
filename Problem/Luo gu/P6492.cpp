#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=2e5+5;
struct node{
    int l,r,len,sum,lNum,rNum,lSum,rSum;
}tree[maxn<<2];
int n,q,x;

inline int Read();
void PushUp(int);
void Build(int,int,int);
void Modify(int,int);

int main(){
    n=Read(),q=Read();
    Build(1,1,n);
    while(q--){
        x=Read();
        Modify(1,x);
        printf("%d\n",tree[1].sum);
    }
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
    tree[point].lNum=tree[lSon].lNum;
    tree[point].rNum=tree[rSon].rNum;
    tree[point].lSum=(tree[lSon].lSum==tree[lSon].len && tree[lSon].rNum==!tree[rSon].lNum) ? (tree[lSon].lSum+tree[rSon].lSum) : (tree[lSon].lSum);
    tree[point].rSum=(tree[rSon].rSum==tree[rSon].len && tree[rSon].lNum==!tree[lSon].rNum) ? (tree[rSon].rSum+tree[lSon].rSum) : (tree[rSon].rSum);
    tree[point].sum=max(max(tree[lSon].sum,tree[rSon].sum),(tree[lSon].rNum==!tree[rSon].lNum) ? (tree[lSon].rSum+tree[rSon].lSum) : 0);
}   
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        tree[point].len=1;
        tree[point].sum=tree[point].lSum=tree[point].rSum=1;
        tree[point].lNum=tree[point].rNum=0;
    }else{
        int mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);       
    }
}
void Modify(int point,int pos){
    if(tree[point].l==tree[point].r){
        tree[point].lNum=tree[point].rNum=!tree[point].lNum;
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(pos<=mid) Modify(lSon,pos);
        else Modify(rSon,pos);
        PushUp(point);
    }
}