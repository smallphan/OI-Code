#include<iostream>
#include<cstdio>
#define LL long long

using namespace std;

const LL Maxq=1e5+5;
struct Node{
    LL L,R,Value;
}Tree[Maxq<<2];
LL T,Q,Mod,Flag,Num[Maxq],Len;

inline LL Read()
{
    LL Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void PushUp(LL Point)
{
    Tree[Point].Value=(Tree[Point<<1].Value*Tree[Point<<1|1].Value)%Mod;
}
void Build(LL Point,LL L,LL R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        Tree[Point].Value=1;
    }else{
        int Mid=(L+R)>>1;
        Build(Point<<1,L,Mid);
        Build(Point<<1|1,Mid+1,R);
        PushUp(Point);
    }
}
void Modify(LL Point,LL Pos,LL Key)
{
    if(Tree[Point].L==Tree[Point].R){
        Tree[Point].Value=Key%Mod;
    }else{
        int Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(Pos<=Mid)Modify(Point<<1,Pos,Key);
        else Modify(Point<<1|1,Pos,Key);
        PushUp(Point);
    }
}
int main()
{
    T=Read();
    while(T--){
        Q=Read(),Mod=Read();
        Build(1,1,Q);
        for(int i=1;i<=Q;i++){
            Flag=Read();
            if(Flag==1){
                Modify(1,i,Read());
            }else{
                Modify(1,Read(),1);
            }
            printf("%lld\n",Tree[1].Value%Mod);
        }
    }
    return 0;
}