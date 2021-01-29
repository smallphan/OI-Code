#include<iostream>
#include<cstdio>
#define LL long long

using namespace std;

const int Maxn=5e5+5;
struct Node{
    LL L,R,Value;
}Tree[Maxn<<2];
LL Flag,N,M,A,B,C,Lazy[Maxn<<2];

inline LL Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(LL Point)
{
    Tree[Point].Value=Tree[Point<<1].Value+Tree[Point<<1|1].Value;
}
void PushDn(LL Point)
{
    if(Lazy[Point]){
        Tree[Point<<1].Value+=(Tree[Point<<1].R-Tree[Point<<1].L+1)*Lazy[Point];
        Tree[Point<<1|1].Value+=(Tree[Point<<1|1].R-Tree[Point<<1|1].L+1)*Lazy[Point];
        Lazy[Point<<1]+=Lazy[Point];
        Lazy[Point<<1|1]+=Lazy[Point];
        Lazy[Point]=0;
    }
}
void Build(LL Point,LL L,LL R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        Tree[Point].Value=Read();
    }else{
        LL Mid=(L+R)>>1;
        Build(Point<<1,L,Mid);
        Build(Point<<1|1,Mid+1,R);
        PushUp(Point);
    }
}
void Modify(LL Point,LL L,LL R,LL Key)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        Lazy[Point]+=Key;
        Tree[Point].Value+=(Tree[Point].R-Tree[Point].L+1)*Key;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(L<=Mid)Modify(Point<<1,L,R,Key);
        if(R>=Mid+1)Modify(Point<<1|1,L,R,Key);
        PushUp(Point);
    }
}
LL Query(LL Point,LL L,LL R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Value;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=0;
        if(L<=Mid)Ans+=Query(Point<<1,L,R);
        if(R>=Mid+1)Ans+=Query(Point<<1|1,L,R);
        return Ans;
    }
}
int main()
{
    N=Read(),M=Read();
    Build(1,1,N);
    while(M--){
        Flag=Read();
        if(Flag==1){
            A=Read(),B=Read(),C=Read();
            Modify(1,A,B,C);
        }else{
            A=Read(),B=Read();
            printf("%lld\n",Query(1,A,B));
        }
    }
    return 0;
}