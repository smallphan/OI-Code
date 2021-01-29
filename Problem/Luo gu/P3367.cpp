#include<iostream>

using namespace std;

const int Maxn=10005;
int N,M,Z,X,Y;
int Father[Maxn];

int Find(int X)
{
    if(X==Father[X])return X;
    else return Father[X]=Find(Father[X]);
}
void Merge(int A,int B)
{
    A=Find(A),B=Find(B);
    if(A!=B)Father[A]=B;
    return;
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        Father[i]=i;
    }
    while(M--){
        cin>>Z>>X>>Y;
        if(Z==1){
            Merge(X,Y);
        }else{
            if(Find(X)==Find(Y)){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}