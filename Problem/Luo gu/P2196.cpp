#include<cstdio>

using namespace std;

const int maxn=25;
struct node{
    int path,num;
}dp[maxn];
int n,mine[maxn],dl[maxn],cnt;
bool check,connect[maxn][maxn];

inline int Read();

int main(){
    n=Read();
    for(int i=1;i<=n;i++) mine[i]=Read();
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            check=Read();
            connect[i][j]=check;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i].num=mine[i];
        int max=0,pos=0;
        for(int j=1;j<=i-1;j++){
            if(connect[j][i] && max<dp[j].num){
                max=dp[j].num;
                pos=j;
            }
        }
        if(max){
            dp[i].num+=dp[pos].num;
            dp[i].path=pos;
        }
    }
    int max=0,pos=0;
    for(int i=1;i<=n;i++){
        if(max<dp[i].num){
            max=dp[i].num;
            pos=i;
        }
    }
    for(int i=pos;i!=0;i=dp[i].path){
        dl[++cnt]=i;
    }
    for(int i=cnt;i>=1;i--){
        printf("%d ",dl[i]);
    }
    printf("\n%d\n",dp[pos].num);
    return 0;
}

inline int Read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}