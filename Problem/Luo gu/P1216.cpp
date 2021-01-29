#include<iostream>
#include<algorithm>

using namespace std;

const int Maxn=1005;
int Delta[Maxn][Maxn];
int DP[Maxn][Maxn];
int Ans;

int main()
{
    int X;
    cin>>X;
    for(int i=1;i<=X;i++){
        for(int j=1;j<=i;j++){
            cin>>Delta[i][j];
        }
    }
    DP[1][1]=Delta[1][1];
    for(int i=2;i<=X;i++){
        for(int j=1;j<=i;j++){
            DP[i][j]=max(DP[i-1][j],DP[i-1][j-1])+Delta[i][j];
        }
    }
    for(int i=1;i<=X;i++){
        Ans=max(Ans,DP[X][i]);
    }
    cout<<Ans<<endl;
    return 0;
}