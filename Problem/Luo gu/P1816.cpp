#include<iostream>
#include<cstdio>

using namespace std;

const int INF=0x3f3f3f3f;
const int Maxn=1e5+5;
struct Node{
    int L,R,Min;
}Tree[Maxn<<2];
int N,M,A,B;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(int Point)
{
    Tree[Point].Min=min(Tree[Point<<1].Min,Tree[Point<<1|1].Min);
}
void Build(int Point,int L,int R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        Tree[Point].Min=Read();
    }else{
        int Mid=(L+R)>>1;
        Build(Point<<1,L,Mid);
        Build(Point<<1|1,Mid+1,R);
        PushUp(Point);
    }
}
int Query(int Point,int L,int R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Min;
    }else{
        int Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=INF;
        if(L<=Mid)Ans=min(Ans,Query(Point<<1,L,R));
        if(R>=Mid+1)Ans=min(Ans,Query(Point<<1|1,L,R));
        return Ans;
    }
}
int main()
{
    N=Read(),M=Read();
    Build(1,1,N);
    while(M--){
        A=Read(),B=Read();
        printf("%d ",Query(1,A,B));
    }
    return 0;
}