#include<iostream>
#include<cstdio>
#define LL long long

using namespace std;

const LL Maxn=100005;
struct Node{
    LL L,R,Num;
    LL Add,Mul;
}Tree[Maxn<<2];
LL Flag,N,M,P,A,B;

inline LL Read()
{
    LL Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(LL Point)
{
    Tree[Point].Num=(Tree[Point<<1].Num+Tree[Point<<1|1].Num)%P;
}
void PushDn(LL Point)
{
    Tree[Point<<1].Num=(Tree[Point<<1].Num*Tree[Point].Mul+(Tree[Point<<1].R-Tree[Point<<1].L+1)*Tree[Point].Add)%P;
    Tree[Point<<1|1].Num=(Tree[Point<<1|1].Num*Tree[Point].Mul+(Tree[Point<<1|1].R-Tree[Point<<1|1].L+1)*Tree[Point].Add)%P;
    Tree[Point<<1].Mul=(Tree[Point<<1].Mul*Tree[Point].Mul)%P;
    Tree[Point<<1|1].Mul=(Tree[Point<<1|1].Mul*Tree[Point].Mul)%P;
    Tree[Point<<1].Add=(Tree[Point<<1].Add*Tree[Point].Mul+Tree[Point].Add)%P;
    Tree[Point<<1|1].Add=(Tree[Point<<1|1].Add*Tree[Point].Mul+Tree[Point].Add)%P;
    Tree[Point].Mul=1;
    Tree[Point].Add=0;
}
void Build(LL Point,LL L,LL R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    Tree[Point].Mul=1;
    if(L==R){
        Tree[Point].Num=Read();
    }else{
        LL Mid=(L+R)>>1;
        Build(Point<<1,L,Mid);
        Build(Point<<1|1,Mid+1,R);
        PushUp(Point);
    }
}
void Add(LL Point,LL L,LL R,LL Key)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        Tree[Point].Add=(Tree[Point].Add+Key)%P;
        Tree[Point].Num=(Tree[Point].Num+(Tree[Point].R-Tree[Point].L+1)*Key)%P;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(L<=Mid)Add(Point<<1,L,R,Key);
        if(R>=Mid+1)Add(Point<<1|1,L,R,Key);
        PushUp(Point);
    }
}
void Mul(LL Point,LL L,LL R,LL Key)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        Tree[Point].Add=(Tree[Point].Add*Key)%P;
        Tree[Point].Mul=(Tree[Point].Mul*Key)%P;
        Tree[Point].Num=(Tree[Point].Num*Key)%P;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(L<=Mid)Mul(Point<<1,L,R,Key);
        if(R>=Mid+1)Mul(Point<<1|1,L,R,Key);
        PushUp(Point);
    }
}
LL Query(LL Point,LL L,LL R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Num%P;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=0;
        if(L<=Mid)Ans=(Ans+Query(Point<<1,L,R))%P;
        if(R>=Mid+1)Ans=(Ans+Query(Point<<1|1,L,R))%P;
        return Ans;
    }
}
int main()
{
    N=Read(),P=Read();
    Build(1,1,N);
    M=Read();
    while(M--){
        Flag=Read(),A=Read(),B=Read();
        switch(Flag){
            case 1:Mul(1,A,B,Read());break;
            case 2:Add(1,A,B,Read());break; 
            case 3:printf("%d\n",Query(1,A,B));break;
        }
    }
    return 0;
}