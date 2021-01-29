#include<iostream>

using namespace std;

int N,A,B,Ans;
bool Judge;

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>B;
        if(B>A){
            Judge=true;
        }
        if(B<A&&Judge){
            Judge=false;
            Ans++;
        }
        A=B;
    }
    cout<<Ans-1<<endl;
    return 0;
}