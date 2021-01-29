#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int INF=0x3f3f3f3f;
const int Maxn=200005;
struct Node{
    int L,R,Value;
}Tree[Maxn<<2];
int N,M,A,B,C;
char Flag;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(int Point)
{
    Tree[Point].Value=max(Tree[Point<<1].Value,Tree[Point<<1|1].Value);
}
void Build(int Point,int L,int R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        Tree[Point].Value=Read();
    }else{
        int Mid=(L+R)>>1;
        Build(Point<<1,L,Mid);
        Build(Point<<1|1,Mid+1,R);
        PushUp(Point);
    }
}
void Modify(int Point,int Pos,int Key)
{
    if(Tree[Point].L==Tree[Point].R){
        Tree[Point].Value=max(Tree[Point].Value,Key);
    }else{
        int Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(Pos<=Mid)Modify(Point<<1,Pos,Key);
        else Modify(Point<<1|1,Pos,Key);
        PushUp(Point);
    }
}
int Query(int Point,int L,int R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Value;
    }else{
        int Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=-INF;
        if(L<=Mid)Ans=max(Ans,Query(Point<<1,L,R));
        if(R>=Mid+1)Ans=max(Ans,Query(Point<<1|1,L,R));
        return Ans;
    }
}
int main()
{
    N=Read(),M=Read();
    Build(1,1,N);
    while(M--){
        scanf("%s",&Flag);
        if(Flag=='U'){
            A=Read(),B=Read();
            Modify(1,A,B);
        }else{
            A=Read(),B=Read();
            printf("%d\n",Query(1,A,B));
        }
    }
    return 0;
}