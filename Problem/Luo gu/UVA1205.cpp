#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=55;
const int maxt=1e4+5;
int n,t,mI,mII,caseNum;
int tim[maxn],dp[maxt][maxn];
bool lTrain[maxn][maxt],rTrain[maxn][maxt];

inline int Read();

int main(){
    while(cin>>n && n!=0){
        caseNum++;
        t=Read();
        memset(tim,0,sizeof(tim));
        memset(lTrain,0,sizeof(lTrain));
        memset(rTrain,0,sizeof(rTrain));
        for(int i=1;i<=n-1;i++) tim[i]=Read();
        mI=Read();
        for(int i=1;i<=mI;i++){
            int tI=Read(),sum=tI;
            for(int j=1;j<=n;j++){
                lTrain[j][sum]=true;
                sum+=tim[j];
            }
        }
        mII=Read();
        for(int i=1;i<=mII;i++){
            int tII=Read(),sum=tII;
            for(int j=n;j>=1;j--){
                rTrain[j][sum]=true;
                sum+=tim[j-1];
            }
        }
        for(int i=1;i<=n-1;i++) dp[t][i]=inf;
        dp[t][n]=0;
        for(int i=t-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                if(j<n && lTrain[j][i] && i+tim[j]<=t)
                    dp[i][j]=min(dp[i][j],dp[i+tim[j]][j+1]);
                if(j>1 && rTrain[j][i] && i+tim[j-1]<=t)
                    dp[i][j]=min(dp[i][j],dp[i+tim[j-1]][j-1]);
            }
        }
        printf("Case Number %d: ",caseNum);
        if(dp[0][1]>=inf) printf("impossible\n");
        else printf("%d\n",dp[0][1]);
    }
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}