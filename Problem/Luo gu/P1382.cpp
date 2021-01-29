#include<map>
#include<cstdio>
#include<algorithm>

#define lSon (point<<1)
#define rSon (point<<1|1)

using namespace std;

const int maxn=1e6+5;
struct nodeI{
    int height,pos,mark;
}line[maxn<<1];
struct nodeII{
    int l,r,len,num,sum;
}tree[maxn<<2];
int n,h,l,r,coor[maxn<<1];
int num[2][maxn<<1],ans[2][maxn<<2],finalAns[2][maxn<<2],finalCnt;
int pointer,cnt,pos,flag;
bool vis[maxn<<2];
map<int,int>findPos;

inline int Read();
void PushUp(int);
bool CMP(nodeI,nodeI);
void Build(int,int,int);
void Modify(int,int,int,int);

int main(){
    n=Read();
    for(int i=1;i<=n;i++){
        h=Read(),l=Read(),r=Read();
        coor[i]=h;
        line[(i<<1)-1]=(nodeI){h,l,1};
        line[(i<<1)]=(nodeI){h,r,-1};
    }
    n<<=1;
    sort(line+1,line+1+n,CMP);
    sort(coor+1,coor+2+n);
    int tot=unique(coor+1,coor+2+n)-coor-1;
    for(int i=1;i<=tot;i++) findPos[coor[i]]=i;
    Build(1,1,tot-1);
    for(int i=1;i<=n;i++){
        Modify(1,1,findPos[line[i].height]-1,line[i].mark);
        num[0][i]=line[i].pos,num[1][i]=tree[1].sum;
    }
    while(pointer<=n){
        ans[0][++cnt]=num[0][pointer],flag=ans[1][cnt]=num[1][pointer];
        while(pointer<=n && flag==num[1][pointer]) pointer++;
        if(pointer>n) break;
        ans[0][++cnt]=num[0][pointer],ans[1][cnt]=flag;
    }
    for(int i=2;i<=cnt+1;i++){
        if(flag==ans[0][i]) continue;
        else{
            flag=ans[0][i];
            finalAns[0][++finalCnt]=ans[0][i-1],finalAns[1][finalCnt]=ans[1][i-1];
            finalAns[0][++finalCnt]=ans[0][i],finalAns[1][finalCnt]=ans[1][i];
        }   
    }
    cnt=pointer=0,finalCnt--;
    while(pointer<=finalCnt){
        ans[0][++cnt]=finalAns[0][pointer],flag=ans[1][cnt]=finalAns[1][pointer];
        while(pointer<=finalCnt && flag==finalAns[1][pointer]) pointer++;
        if(pointer>finalCnt) break;
        ans[0][++cnt]=finalAns[0][pointer],ans[1][cnt]=flag;
    }
    printf("%d\n",cnt-1);
    for(int i=2;i<=cnt;i++) printf("%d %d\n",ans[0][i],ans[1][i]);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
bool CMP(nodeI a,nodeI b){
    return a.pos<b.pos;
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