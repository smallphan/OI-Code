#include<iostream>
#include<algorithm>

using namespace std;

int N,Ans,X,Y,Unhappy[3005];

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>X>>Y;
        X=X+Y;
        Unhappy[i]=Unhappy[i-1]+X-8;
        Ans+=Unhappy[i];
    }
    cout<<Ans<<endl;
    return 0;
}