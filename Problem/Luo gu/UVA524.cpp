#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n,cnt,num[20];
bool check[60]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0};
bool vis[20];

void dfs(int);

int main(){
    while(cin>>n && ++cnt){
        if(cnt-1) printf("\n");
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        printf("Case %d:\n",cnt);
        num[1]=1;
        vis[1]=true;
        dfs(2);
    }
    return 0;
}

void dfs(int now){
    if(now==n+1 && check[1+num[n]]){
        for(int i=1;i<=n;i++){
            printf("%d",num[i]);
            if(i!=n) printf(" ");
        }
        printf("\n");
    }else{
        for(int i=2;i<=n;i++){
            if(!vis[i] && check[i+num[now-1]]){
                num[now]=i;
                vis[i]=true;
                dfs(now+1);
                vis[i]=false;
            }
        }
    }
}