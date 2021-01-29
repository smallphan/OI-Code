#include<iostream>
#define LL long long

using namespace std;

LL Fst,Lst;
int Ans[10];

int main()
{
    cin>>Fst>>Lst;
    for(int i=Fst;i<=Lst;i++){
        for(int Find=i;Find;Find/=10){
            int X=Find%10;
            Ans[X]++;
        }
    }
    for(int i=0;i<=9;i++){
        cout<<Ans[i]<<' ';
    }
    return 0;
}