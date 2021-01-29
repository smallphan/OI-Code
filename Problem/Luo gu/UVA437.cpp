#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=95;
struct node{
    int x,y,z;
    bool operator > (const node& T){
        return ((x>T.x && y>T.y) || (x>T.y && y>T.x));
    }
}cube[maxn];
int n,m,x,y,z,cnt,finalAns,ans[maxn];

inline int Read();
bool Input();
int Solve();
int DP(int);

int main(){
    while(Input()) printf("Case %d: maximum height = %d\n",++cnt,Solve());
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
bool Input(){
    n=Read();
    if(!n) return false;
    m=n*3;
    for(int i=1;i<=m;i+=3){
        x=Read(),y=Read(),z=Read();
        cube[i]=(node){x,y,z};
        cube[i+1]=(node){x,z,y};
        cube[i+2]=(node){y,z,x};
    }
    return true;
}
int Solve(){
    finalAns=0;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=m;i++) finalAns=max(DP(i),finalAns);
    return finalAns;
}
int DP(int id){
    if(ans[id]) return ans[id];
    ans[id]=cube[id].z;
    for(int i=1;i<=m;i++){
        if(cube[id]>cube[i]) ans[id]=max(ans[id],DP(i)+cube[id].z);
    }
    return ans[id];
}