#include<cstdio>
#include<algorithm>
#include<cmath>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

typedef long long ll;
const int maxn=2e5+5;
struct node{
    int l,r;
    ll tag;
    double sinNum,cosNum;
}tree[maxn<<2];
int n,m,opt,a,b,v;

inline int Read();
void UpDate(int,double,double);
void PushUp(int);
void PushDn(int);
void Build(int,int,int);
void Modify(int,int,int,int);
double Query(int,int,int);

//*****
int main(){
    n=Read();
    Build(1,1,n);
    m=Read();
    while(m--){
        opt=Read();
        if(opt==1){
            a=Read(),b=Read(),v=Read();
            Modify(1,a,b,v);
        }else{
            a=Read(),b=Read();
            printf("%.1lf\n",Query(1,a,b));
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
void UpDate(int point,double sinNum,double cosNum){
    double sinPoint=tree[point].sinNum,cosPoint=tree[point].cosNum;
    tree[point].sinNum=sinPoint*cosNum+cosPoint*sinNum;
    tree[point].cosNum=cosPoint*cosNum-sinPoint*sinNum;
}
void PushUp(int point){
    tree[point].sinNum=tree[lSon].sinNum+tree[rSon].sinNum;
    tree[point].cosNum=tree[lSon].cosNum+tree[rSon].cosNum;
}
void PushDn(int point){
    if(tree[point].tag){
        double sinNum=sin(tree[point].tag),cosNum=cos(tree[point].tag);
        UpDate(lSon,sinNum,cosNum);
        UpDate(rSon,sinNum,cosNum);
        tree[lSon].tag+=tree[point].tag;
        tree[rSon].tag+=tree[point].tag;
        tree[point].tag=0;
    }
}
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        int num=Read();
        tree[point].sinNum=sin(num);
        tree[point].cosNum=cos(num);
    }else{
        int mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);
    }
}
void Modify(int point,int l,int r,int key){
    if(l<=tree[point].l && r>=tree[point].r){
        double sinNum=sin(key),cosNum=cos(key);
        UpDate(point,sinNum,cosNum);
        tree[point].tag+=key;
    }else{
        PushDn(point);
        int mid=(tree[point].l+tree[point].r)>>1;
        if(l<=mid) Modify(lSon,l,r,key);
        if(r>=mid+1) Modify(rSon,l,r,key);
        PushUp(point);
    }
}
double Query(int point,int l,int r){
    if(l<=tree[point].l && r>=tree[point].r){
        return tree[point].sinNum;
    }else{
        PushDn(point);
        int mid=(tree[point].l+tree[point].r)>>1;
        double ans=0;
        if(l<=mid) ans+=Query(lSon,l,r);
        if(r>=mid+1) ans+=Query(rSon,l,r);
        return ans; 
    }
}