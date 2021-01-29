#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn=1e4+5;
int N,M,A,B,C;
int AnsI,AnsII;
int Tree[Maxn],Build[Maxn],Cut[Maxn];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    N=Read(),M=Read();
    for(int i=0;i<=N;i++)Tree[i]=true;
    for(int i=1;i<=M;i++){
        A=Read(),B=Read(),C=Read();
        if(A){
            for(int i=B;i<=C;i++){
                if(!Tree[i]){
                    Tree[i]=2;
                    Build[i]++;
                }
            }   
        }else{
            for(int i=B;i<=C;i++){
                if(Tree[i]){
                    Tree[i]=0;
                    Cut[i]++;
                }
            }
        }
    }
    for(int i=0;i<=N;i++){
        if(Tree[i]==2)AnsI++;
        if(Cut[i]>=2)AnsII+=Cut[i]-1;
    }
    printf("%d\n%d\n",AnsI,AnsII);
    return 0;
}