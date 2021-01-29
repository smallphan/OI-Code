#include<iostream>
#define LL long long

using namespace std;

LL X,Y,Ans,Flag;

inline LL GCD(LL A,LL B){return B?GCD(B,A%B):A;}
int main()
{
    cin>>X>>Y;
    for(LL i=1;i*i<=X*Y;i++){
        if((X*Y)%i==0){
            if(GCD(i,X*Y/i)==X){
                Ans++;
                if(i*i==X*Y)Flag=1;
            }
        }
    }
    cout<<Ans*2-Flag<<endl;
    return 0;
}