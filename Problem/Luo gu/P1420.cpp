#include<iostream>
#include<algorithm>

using namespace std;

int Num[10005],DP,N;
int Ans;

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Num[i];
        DP=Num[i]==Num[i-1]+1?DP+1:1;
        Ans=max(Ans,DP);
    }
    cout<<Ans<<endl;
    return 0;
}