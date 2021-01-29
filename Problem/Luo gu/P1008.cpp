#include<iostream>
#include<algorithm>

using namespace std;

int Num[10]={0,1,2,3,4,5,6,7,8,9};
int A,B,C;

int Get(int L,int R)
{
    int Ans=0;
    for(int i=L;i<=R;i++){
        Ans=Ans*10+Num[i];
    }
    return Ans;
}
int main()
{
    do{
        A=Get(1,3),B=Get(4,6),C=Get(7,9);
        if(2*A==B&&3*A==C){
            cout<<A<<' '<<B<<' '<<C<<endl;
        }
    }while(next_permutation(Num+1,Num+10));
    return 0;
}