#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=105;
struct node{
    int num,time;
}dp[maxn][maxn];
int n,m,r,ans,tag=-999;
int rmb[maxn],rp[maxn],time[maxn];

inline int Read();

//*****
int main(){
    n=Read();
    for(int i=1;i<=n;i++){
        rmb[i]=Read(),rp[i]=Read(),time[i]=Read();
    }
    m=Read(),r=Read();
    for(int i=1;i<=n;i++){
        for(int j=m;j>=rmb[i];j--){
            for(int k=r;k>=rp[i];k--){
                if(dp[j][k].num<dp[j-rmb[i]][k-rp[i]].num+1){
                    dp[j][k].num=dp[j-rmb[i]][k-rp[i]].num+1;
                    dp[j][k].time=dp[j-rmb[i]][k-rp[i]].time+time[i];
                }else if(dp[j][k].num==dp[j-rmb[i]][k-rp[i]].num+1){
                    dp[j][k].time=min(dp[j][k].time,dp[j-rmb[i]][k-rp[i]].time+time[i]);
                }
            }
        }
    }
    printf("%d\n",dp[m][r].time);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}