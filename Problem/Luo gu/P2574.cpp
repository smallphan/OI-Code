#include<iostream>
#include<cstdio>
#define Lson Point<<1
#define Rson Point<<1|1

using namespace std;

const int Maxn=2e5+5;
struct Node{
    int L,R,Len,Sum;
    bool Lazy;
}Tree[Maxn<<2];
char STR;
int N,M,Opt,A,B;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(int Point)
{
    Tree[Point].Len=Tree[Lson].Len+Tree[Rson].Len;
    Tree[Point].Sum=Tree[Lson].Sum+Tree[Rson].Sum;
}
void PushDn(int Point)
{
    if(Tree[Point].Lazy){
        Tree[Lson].Sum=Tree[Lson].Len-Tree[Lson].Sum;
        Tree[Rson].Sum=Tree[Rson].Len-Tree[Rson].Sum;
        Tree[Lson].Lazy=!Tree[Lson].Lazy;
        Tree[Rson].Lazy=!Tree[Rson].Lazy;
        Tree[Point].Lazy=false;
    }
}
void Build(int Point,int L,int R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        cin>>STR;
        if(STR=='1'){
            Tree[Point].Sum=1;
        }
        Tree[Point].Len=1;
    }else{
        int Mid=(L+R)>>1;
        Build(Lson,L,Mid);
        Build(Rson,Mid+1,R);
        PushUp(Point);
    }
}
void Modify(int Point,int L,int R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        Tree[Point].Sum=Tree[Point].Len-Tree[Point].Sum;
        Tree[Point].Lazy=!Tree[Point].Lazy;
    }else{
        PushDn(Point);
        int Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(L<=Mid)Modify(Lson,L,R);
        if(R>=Mid+1)Modify(Rson,L,R);
        PushUp(Point);
    }
}
int Query(int Point,int L,int R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Sum;
    }else{
        PushDn(Point);
        int Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=0;
        if(L<=Mid)Ans+=Query(Lson,L,R);
        if(R>=Mid+1)Ans+=Query(Rson,L,R);
        return Ans;
    }
}
int main()
{
    N=Read(),M=Read();
    Build(1,1,N);
    while(M--){
        Opt=Read(),A=Read(),B=Read();
        if(Opt){
            printf("%d\n",Query(1,A,B));
        }else{
            Modify(1,A,B);
        }
    }
    return 0;
}