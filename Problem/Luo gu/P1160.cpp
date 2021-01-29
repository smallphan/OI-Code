#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn=1e5+5;
struct Node{
    int From,To;
}Stu[Maxn];
int N,M,K,P;
bool In[Maxn];

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    N=Read();
    for(int i=1;i<=N;i++)Stu[i].To=-1;
    Stu[0].To=1;
    In[1]=true;
    for(int i=2;i<=N;i++){
        K=Read(),P=Read();
        if(P){
            Stu[Stu[K].To].From=i;
            Stu[i].To=Stu[K].To;
            Stu[i].From=K;
            Stu[K].To=i;
        }else{
            Stu[Stu[K].From].To=i;
            Stu[i].From=Stu[K].From;
            Stu[i].To=K;
            Stu[K].From=i;
        }
        In[i]=true;
    }
    M=Read();
    for(int i=1;i<=M;i++){
        K=Read();
        if(In[K]==true){
            Stu[Stu[K].From].To=Stu[K].To;
            Stu[Stu[K].To].From=Stu[K].From;
            Stu[K].To=-1;
            In[K]=false;
        }
    }
    for(int i=0;i!=-1;i=Stu[i].To){
        if(i){
            printf("%d ",i);
        }
    }
    return 0;
}