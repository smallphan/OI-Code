#include<iostream>

using namespace std;

int n,Sum,TL[105],Len,Ans[1000005][11];

int DFS(int i)
{
    if(Sum>n){
        return 0;
    }
    if(i==11){
        if(Sum==n){
            Len++;
            for(int j=1;j<=10;j++){
                Ans[Len][j]=TL[j];
            }
        }
        return 0;
    }
    for(int a=1;a<=3;a++){
        Sum+=a;
        TL[i]=a;
        DFS(i+1);
        Sum-=a;
    }
}
int main()
{
    cin>>n;
    if(n<10||n>30){
        cout<<0;
        return 0;
    }
    DFS(1);
    cout<<Len<<endl;
    for(int i=1;i<=Len;i++){
        for(int j=1;j<=10;j++){
            cout<<Ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}