#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=35;
int n,m,cnt,tot;
bool vis[maxn],unicom[maxn][maxn];
string a,b;
map<string,int>up;
map<int,string>dn;
//[up] string=>int
//[dn] int=>string

void add(string,string);

int main(){
    while(cin>>n>>m && n && ++cnt){
        memset(vis,0,sizeof(vis));
        memset(unicom,0,sizeof(unicom));
        tot=0;
        up.clear(),dn.clear();
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            add(a,b);
        }
        for(int i=1;i<=n;i++) unicom[i][i]=true;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                if(unicom[i][k]){
                    for(int j=1;j<=n;j++){
                        if(unicom[k][j]) unicom[i][j]=true;
                    }
                }
            }
        }
        printf("Calling circles for data set %d:\n",cnt);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cout<<dn[i];
                vis[i]=true;
                for(int j=1;j<=n;j++){
                    if(unicom[i][j] && unicom[j][i] && !vis[j]){
                        cout<<", "<<dn[j];
                        vis[j]=true;
                    }
                }
                printf("\n");
            }
        }
    }
}

void add(string a,string b){
    if(!up[a]) up[a]=++tot;
    if(!up[b]) up[b]=++tot;
    dn[up[a]]=a,dn[up[b]]=b;
    unicom[up[a]][up[b]]=true;
}