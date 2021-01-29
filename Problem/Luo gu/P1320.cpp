#include<iostream>
#include<cmath>

using namespace std;

int Num[40005],Len,Ans,Judge;
char X;

int main()
{
    while(cin>>X){
        Num[++Len]=(int)X-48;
    }
    cout<<sqrt(Len)<<' ';
    // for(int i=1;i<=Len;i++){
    //     cout<<Num[i];
    //     if(i%7==0)cout<<endl;
    // }
    for(int i=1;i<=Len;i++){
        if(Num[i]==Judge){
            Ans++;
        }else{
            Judge=!Judge;
            cout<<Ans<<' ';
            Ans=1;
        }
    }
    cout<<Ans;
    return 0;
}