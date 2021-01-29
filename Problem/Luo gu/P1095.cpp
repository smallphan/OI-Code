#include<iostream>
#include<algorithm>

using namespace std;

const int Maxn=3e5+5;
int M,S,T;
int DP[Maxn];

int main()
{
    cin>>M>>S>>T;
    for(int i=1;i<=T;i++){
        if(M>=10)DP[i]=DP[i-1]+60,M-=10;
        else DP[i]=DP[i-1],M+=4;
    }
    for(int i=1;i<=T;i++){
        DP[i]=max(DP[i],DP[i-1]+17);
        if(DP[i]>=S){
            cout<<"Yes"<<endl<<i<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl<<DP[T]<<endl;
    return 0;
}