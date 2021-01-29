#include<iostream>
#include<map>

using namespace std;

int n,c,Num[200005];
long long Ans;
map<int,int>K;

int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>Num[i];
        K[Num[i]]++;
    }
    for(int i=1;i<=n;i++){
        Ans+=K[Num[i]+c];
    }
    cout<<Ans<<endl;
    return 0;
}