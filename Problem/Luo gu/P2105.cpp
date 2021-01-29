#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int Max=2e4+5;
int n,m,k,x[Max],y[Max];
int Ans,Sum;
bool Vis[Max],Flag[Max];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    n=Read(),m=Read(),k=Read();
    for(int i=1;i<=k;i++){
        x[i]=Read(),y[i]=Read();
        Vis[x[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(Vis[i])continue;
        memset(Flag,false,sizeof(Flag));
        Sum=m;
        for(int j=1;j<=k;j++){
            if(Flag[y[j]]==false){
                Flag[y[j]]=true;
                Sum--;
            }
            if(y[j]-x[j]+i>=1&&y[j]-x[j]+i<=m&&Flag[y[j]-x[j]+i]==false){
                Flag[y[j]-x[j]+i]=true;
                Sum--;
            }
            if(y[j]+x[j]-i>=1&&y[j]+x[j]-i<=m&&Flag[y[j]+x[j]-i]==false){
                Flag[y[j]+x[j]-i]=true;
                Sum--;
            }
        }
        Ans+=Sum;
    }
    cout<<Ans<<endl;
    return 0;
}