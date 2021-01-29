#include<iostream>

using namespace std;

int N,A,Sum,Judge;
int Num[40005],Len;

int main()
{
    cin>>N;
    while(Sum!=N*N){
        cin>>A;
        Sum+=A;
        while(A--){
            Num[++Len]=Judge;
        }
        Judge=!Judge;
    }
    for(int i=1;i<=N*N;i++){
        cout<<Num[i];
        if(i%N==0)cout<<endl;
    }
    return 0;
}