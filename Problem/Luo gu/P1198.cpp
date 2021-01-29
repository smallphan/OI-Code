#include<algorithm>
#include<iostream>
#include<cstdio>
#define Lson Point<<1
#define Rson Point<<1|1
#define LL long long

using namespace std;

const LL INF=-(1<<30);
const int Maxn=2e5+5;
struct Node{
    LL L,R,Max;
}Tree[Maxn<<2];
LL X,M,D,End,Tag;
char Flag[2];

inline LL Read()
{
    LL Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(LL Point)
{
    Tree[Point].Max=max(Tree[Lson].Max,Tree[Rson].Max);
}
void Build(LL Point,LL L,LL R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        return;
    }else{
        LL Mid=(L+R)>>1;
        Build(Lson,L,Mid);
        Build(Rson,Mid+1,R);
    }
}
void Modify(LL Point,LL Pos,LL Key)
{
    if(Tree[Point].L==Tree[Point].R){
        Tree[Point].Max=Key;
    }else{
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(Pos<=Mid)Modify(Lson,Pos,Key);
        if(Pos>=Mid+1)Modify(Rson,Pos,Key);
        PushUp(Point);
    }
}
LL Query(LL Point,LL L,LL R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Max;
    }else{
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=INF;
        if(L<=Mid)Ans=max(Ans,Query(Lson,L,R));
        if(R>=Mid+1)Ans=max(Ans,Query(Rson,L,R));
        return Ans;
    }
}
int main()
{
    M=Read(),D=Read();
    Build(1,1,M);
    while(M--){
        scanf("%s",&Flag);
        X=Read();
        if(Flag[0]=='A'){
            Modify(1,End+1,(X+Tag)%D);
            End++;
        }else{
            if(X==0)Tag=0;
            else Tag=Query(1,End-X+1,End)%D;
            printf("%lld\n",Tag);
        }
    }
    return 0;
}