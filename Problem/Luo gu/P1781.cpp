#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

struct Node{
    string Tic;
    int Pos;
}Pre[25];
int N;

bool CMP(Node A,Node B)
{
    if(A.Tic.size()==B.Tic.size())return A.Tic>B.Tic;
    else return A.Tic.size()>B.Tic.size();
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Pre[i].Tic;
        Pre[i].Pos=i;
    }
    sort(Pre+1,Pre+1+N,CMP);
    cout<<Pre[1].Pos<<endl<<Pre[1].Tic<<endl;
    return 0;
}