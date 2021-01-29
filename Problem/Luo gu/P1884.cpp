#include<map>
#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

typedef long long ll;
const int maxn=1e4+5;
struct nodeI{
    int l,r,height,mark;
    bool operator < (nodeI& line){
        return height<line.height;
    }
}line[maxn<<1];
struct nodeII{
    int l,r,len,num,sum;
}tree[maxn<<2];
int n,xI,yI,xII,yII;
int coor[maxn<<1];
ll ans;
map<int,int>findPos;

inline int Read();
void PushUp(int);
void Build(int,int,int);
void Modify(int,int,int,int);

int main(){
    n=Read();
    for(int i=1;i<=n;i++){
        xI=Read(),yI=Read(),xII=Read(),yII=Read();
        coor[(i<<1)-1]=xI,coor[(i<<1)]=xII;
        line[(i<<1)-1]=(nodeI){xI,xII,yII,1};
        line[(i<<1)]=(nodeI){xI,xII,yI,-1};
    }
    n<<=1;
    sort(coor+1,coor+1+n);
    sort(line+1,line+1+n);
    int tot=unique(coor+1,coor+1+n)-coor-1;
    for(int i=1;i<=tot;i++) findPos[coor[i]]=i;
    Build(1,1,tot-1);
    for(int i=1;i<n;i++){
        Modify(1,findPos[line[i].l],findPos[line[i].r]-1,line[i].mark);
        ans+=(ll)tree[1].sum*(ll)(line[i+1].height-line[i].height);
    }
    printf("%lld\n",ans);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
void PushUp(int point){
    if(tree[point].l!=tree[point].r) tree[point].len=tree[lSon].len+tree[rSon].len;
    if(tree[point].num) tree[point].sum=tree[point].len;
    else tree[point].sum=tree[lSon].sum+tree[rSon].sum;
}
void Build(int point,int l,int r){
    tree[point].l=l,tree[point].r=r;
    if(l==r){
        tree[point].len=coor[l+1]-coor[l];
    }else{
        int mid=(l+r)>>1;
        Build(lSon,l,mid);
        Build(rSon,mid+1,r);
        PushUp(point);
    }
}
void Modify(int point,int l,int r,int key){
    if(l<=tree[point].l && r>=tree[point].r){
        tree[point].num+=key;
        PushUp(point);
    }else{
        int mid=(tree[point].l+tree[point].r)>>1;
        if(l<=mid) Modify(lSon,l,r,key);
        if(r>=mid+1) Modify(rSon,l,r,key);
        PushUp(point);
    }
}