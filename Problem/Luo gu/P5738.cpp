#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=0x3f3f3f3f;
int n,m,ans,score,sum,maxNum,minNum;

inline int read();

int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        sum=0,maxNum=-inf,minNum=inf;
        for(int j=1;j<=m;j++){
            score=read();
            sum+=score;
            maxNum=max(maxNum,score);
            minNum=min(minNum,score);
        }
        sum=sum-(maxNum+minNum);
        ans=max(ans,sum);
    }
    printf("%.2lf",(double)ans/(m-2));
}

inline int read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}