#include<iostream>
#include<cstdio>
#include<algorithm>
#define Lson Point<<1
#define Rson Point<<1|1
#define LL long long

using namespace std;

const int Maxn=2e5+5;
struct Node{
    int L,R,Len,Sum,SumL,SumR;
}Tree[2][Maxn<<2];
int HNum[Maxn],VNum[Maxn];
int W,H,Q,X;
LL Ans;
char Opt;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int Max(int A,int B){return A>B?A:B;}
void PushUp(int Point,int Flag)
{
    Tree[Flag][Point].Len=Tree[Flag][Lson].Len+Tree[Flag][Rson].Len;
    Tree[Flag][Point].SumL=(Tree[Flag][Lson].SumL==Tree[Flag][Lson].Len) ? (Tree[Flag][Lson].SumL+Tree[Flag][Rson].SumL) : (Tree[Flag][Lson].SumL);
    Tree[Flag][Point].SumR=(Tree[Flag][Rson].SumR==Tree[Flag][Rson].Len) ? (Tree[Flag][Rson].SumR+Tree[Flag][Lson].SumR) : (Tree[Flag][Rson].SumR);
    Tree[Flag][Point].Sum=Max(Max(Tree[Flag][Lson].Sum,Tree[Flag][Rson].Sum),Tree[Flag][Lson].SumR+Tree[Flag][Rson].SumL);
}
void Build(int Point,int L,int R,int Flag)
{
    Tree[Flag][Point].L=L,Tree[Flag][Point].R=R;
    if(L==R){
        Tree[Flag][Point].Len=Tree[Flag][Point].Sum=Tree[Flag][Point].SumL=Tree[Flag][Point].SumR=1;
    }else{
        int Mid=(L+R)>>1;
        Build(Lson,L,Mid,Flag);
        Build(Rson,Mid+1,R,Flag);
        PushUp(Point,Flag);
    }
}
void Modify(int Point,int Pos,int Flag)
{
    if(Tree[Flag][Point].L==Tree[Flag][Point].R){
        Tree[Flag][Point].Sum=Tree[Flag][Point].SumL=Tree[Flag][Point].SumR=0;
    }else{
        int Mid=(Tree[Flag][Point].L+Tree[Flag][Point].R)>>1;
        if(Pos<=Mid)Modify(Lson,Pos,Flag);
        else Modify(Rson,Pos,Flag);
        PushUp(Point,Flag);
    }
}
int main()
{
    W=Read(),H=Read(),Q=Read();
    Build(1,1,W-1,0);
    Build(1,1,H-1,1);
    while(Q--){
        scanf("%s",&Opt);
        X=Read();
        if(Opt=='H'){
            Modify(1,X,1);
        }else{
            Modify(1,X,0);
        }
        Ans=(LL)(Tree[1][1].Sum+1)*(Tree[0][1].Sum+1);
        printf("%lld\n",Ans);
    }
    return 0;
}