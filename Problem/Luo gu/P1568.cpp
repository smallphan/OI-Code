#include<iostream>

using namespace std;

int N,M,Speed,Time,Len;
int SpeedA[1000005],SpeedB[1000005];
long long RouteA,RouteB;
long long Ans,Win;

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>Speed>>Time;
        while(Time--){
            SpeedA[++Len]=Speed;
        }
    }
    Len=0;
    for(int i=1;i<=M;i++){
        cin>>Speed>>Time;
        while(Time--){
            SpeedB[++Len]=Speed;
        }
    }
    for(int i=1;i<=Len;i++){
        RouteA+=SpeedA[i];
        RouteB+=SpeedB[i];
        if(RouteA>RouteB){
            if(Win==-1){
                Ans++;
            }
            Win=1;
        }else if(RouteA<RouteB){
            if(Win==1){
                Ans++;
            }
            Win=-1;
        }
    }
    cout<<Ans<<endl;
    return 0;
}