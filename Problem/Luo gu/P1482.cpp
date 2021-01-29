#include<iostream>

using namespace std;

char x;
int A[5],B[5],Num;

int GCD(int A,int B)
{
    if(B==0)return A;
    return GCD(B,A%B);
}
int main()
{
    for(int i=1;i<=2;i++){
        cin>>A[i]>>x>>B[i];
    }
    A[1]=A[1]*A[2];
    B[1]=B[1]*B[2];
    Num=GCD(A[1],B[1]);
    A[1]/=Num;
    B[1]/=Num;
    cout<<B[1]<<' '<<A[1];
    return 0;
}