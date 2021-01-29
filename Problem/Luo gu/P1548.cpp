#include<iostream>
#include<algorithm>

using namespace std;

int N,M,Sum,AZ,AC;

int Find(int i,int j)
{
    return (N-i+1)*(M-j+1);
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==j){
                AZ+=Find(i,i);
            }else{
                AC+=Find(i,j);
            }
        }
    }
    cout<<AZ<<' '<<AC;
    return 0;
}