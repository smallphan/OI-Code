#include<iostream>
#include<cstdio>
#include<algorithm>
#define Lson Point<<1
#define Rson Point<<1|1

using namespace std;

const int Maxn=5e5+5;
struct Node{
    int L,R,Len,Sum,SumL,SumR,Lazy;
}Tree[Maxn<<2];
int N,M,Flag,A,B;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int Max(int A,int B){return A>B?A:B;}
void PushUp(int Point)
{
    Tree[Point].Len=Tree[Lson].Len+Tree[Rson].Len;
    Tree[Point].SumL=(Tree[Lson].SumL==Tree[Lson].Len) ? (Tree[Lson].SumL+Tree[Rson].SumL) : Tree[Lson].SumL;
    Tree[Point].SumR=(Tree[Rson].SumR==Tree[Rson].Len) ? (Tree[Rson].SumR+Tree[Lson].SumR) : Tree[Rson].SumR;
    Tree[Point].Sum=Max(Max(Tree[Lson].Sum,Tree[Rson].Sum),Tree[Lson].SumR+Tree[Rson].SumL);
}
void PushDn(int Point)
{
    if(Tree[Point].Lazy==1){
        Tree[Lson].Lazy=Tree[Rson].Lazy=1;
        Tree[Lson].Sum=Tree[Lson].SumL=Tree[Lson].SumR=0;
        Tree[Rson].Sum=Tree[Rson].SumL=Tree[Rson].SumR=0;
    }else if(Tree[Point].Lazy==2){
        Tree[Lson].Lazy=Tree[Rson].Lazy=2;
        Tree[Lson].Sum=Tree[Lson].SumL=Tree[Lson].SumR=Tree[Lson].Len;
        Tree[Rson].Sum=Tree[Rson].SumL=Tree[Rson].SumR=Tree[Rson].Len;
    }
    Tree[Point].Lazy=0;
}
void Build(int Point,int L,int R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        Tree[Point].Len=Tree[Point].Sum=Tree[Point].SumL=Tree[Point].SumR=1;
    }else{
        int Mid=(L+R)>>1;
        Build(Lson,L,Mid);
        Build(Rson,Mid+1,R);
        PushUp(Point);
    }
}
void Modify(int Point,int L,int R,int Tag)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        if(Tag==1)Tree[Point].Sum=Tree[Point].SumL=Tree[Point].SumR=0;
        else Tree[Point].Sum=Tree[Point].SumL=Tree[Point].SumR=Tree[Point].Len;
        Tree[Point].Lazy=Tag;
    }else{
        PushDn(Point);
        int Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(L<=Mid)Modify(Lson,L,R,Tag);
        if(R>=Mid+1)Modify(Rson,L,R,Tag);
        PushUp(Point);
    }
}
int Query(int Point,int Length)
{
    if(Tree[Point].L==Tree[Point].R){
        return Tree[Point].L;
    }else{
        PushDn(Point);
        int Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(Tree[Lson].Sum>=Length)return Query(Lson,Length);
        else if(Tree[Lson].SumR+Tree[Rson].SumL>=Length)return Mid-Tree[Lson].SumR+1;
        else return Query(Rson,Length);
    }
}
int main()
{
    N=Read(),M=Read();
    Build(1,1,N);
    while(M--){
        Flag=Read();
        if(Flag==1){
            A=Read();
            if(Tree[1].Sum>=A){
                int Left=Query(1,A);
                printf("%d\n",Left);
                Modify(1,Left,Left+A-1,1);
            }else{
                printf("0\n");
            }
        }else{
            A=Read(),B=Read();
            Modify(1,A,A+B-1,2);
        }
    }
    return 0;
}