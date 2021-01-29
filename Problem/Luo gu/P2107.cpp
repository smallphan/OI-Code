#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
struct node{
    ll x,t;
}coom[maxn];//coom->Computer Room
ll n,m,time,ans,ak;
priority_queue<ll>heap;

inline ll Read();
bool CMP(node a,node b);

int main(){
    n=Read(),m=Read();
    for(int i=1;i<=n;i++){
        coom[i].x=Read();
        coom[i].t=Read();
    }
    sort(coom+1,coom+1+n,CMP);
    for(int i=1;i<=n;i++){
        time+=coom[i].x-coom[i-1].x;
        heap.push(coom[i].t);
        ak++;
        time+=coom[i].t;
        while(!heap.empty() && time>m){
            ak--;
            time-=heap.top();
            heap.pop();
        }
        if(time>m) break;
        ans=max(ans,ak);
    }
    printf("%lld\n",ans);
    return 0;
}

inline ll Read(){
    ll ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}
bool CMP(node a,node b){
    return a.x<b.x;
}