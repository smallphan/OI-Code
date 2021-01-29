#include<iostream>

using namespace std;

int Ans[1005],Sum[1005];
int n,Len=1;

int High_C(int a)
{
    for(int j=1;j<=Len;j++){
        Ans[j]*=a;
    }
    for(int j=1;j<=Len-1;j++){
        if(Ans[j]>=10){
            Ans[j+1]+=Ans[j]/10;
            Ans[j]%=10;
        }
    }
    while(Ans[Len]>=10){
        Ans[Len+1]=Ans[Len]/10;
        Ans[Len]%=10;
        Len++;
    }
}
int High_J(int a)
{
    for(int j=1;j<=Len;j++){
        Sum[j]+=Ans[j];
    }
    for(int j=1;j<=Len-1;j++){
        if(Sum[j]>=10){
            Sum[j+1]+=Sum[j]/10;
            Sum[j]%=10;
        }
    }
    while(Sum[Len]>=10){
        Sum[Len+1]=Sum[Len]/10;
        Sum[Len]%=10;
        Len++;
    }
}
int main()
{
    cin>>n;
    Ans[1]=1;
    for(int i=1;i<=n;i++){
        High_C(i);
        High_J(i);
    }
    for(int i=Len;i>=1;i--){
        cout<<Sum[i];
    }
    return 0;
}