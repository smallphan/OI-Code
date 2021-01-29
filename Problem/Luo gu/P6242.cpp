#include<iostream>
#include<cstdio>
#define LL long long

using namespace std;

const LL INF=-1e18;
const LL Maxn=5e5+5;
struct NodeI{
    LL L,R;
    LL Add_A,Add_A1,Add_B,Add_B1;
    LL MaxA,SecMaxA,MaxB,Sum,Cnt;
}Tree[Maxn<<2];
LL Flag,N,M,A,B;

inline LL Read()
{
    LL Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
void UpDate(LL Point,LL K1,LL K2,LL K3,LL K4){
    Tree[Point].Sum+=K1*Tree[Point].Cnt+K3*(Tree[Point].R-Tree[Point].L+1-Tree[Point].Cnt);
    Tree[Point].MaxB=max(Tree[Point].MaxB,Tree[Point].MaxA+K2);
    Tree[Point].Add_B=max(Tree[Point].Add_B,Tree[Point].Add_A+K2);
    Tree[Point].Add_B1=max(Tree[Point].Add_B1,Tree[Point].Add_A1+K4);
    Tree[Point].MaxA+=K1;
    Tree[Point].Add_A+=K1;
    Tree[Point].Add_A1+=K3;
    if(Tree[Point].SecMaxA!=INF)Tree[Point].SecMaxA+=K3;
}
void PushUp(LL Point)
{
    Tree[Point].MaxA=max(Tree[Point<<1].MaxA,Tree[Point<<1|1].MaxA);
    Tree[Point].MaxB=max(Tree[Point<<1].MaxB,Tree[Point<<1|1].MaxB);
    if(Tree[Point<<1].MaxA==Tree[Point<<1|1].MaxA){
        Tree[Point].SecMaxA=max(Tree[Point<<1].SecMaxA,Tree[Point<<1|1].SecMaxA);
        Tree[Point].Cnt=Tree[Point<<1].Cnt+Tree[Point<<1|1].Cnt;
    }else if(Tree[Point<<1].MaxA>Tree[Point<<1|1].MaxA){
        Tree[Point].SecMaxA=max(Tree[Point<<1].SecMaxA,Tree[Point<<1|1].MaxA);
        Tree[Point].Cnt=Tree[Point<<1].Cnt;
    }else{
        Tree[Point].SecMaxA=max(Tree[Point<<1].MaxA,Tree[Point<<1|1].SecMaxA);
        Tree[Point].Cnt=Tree[Point<<1|1].Cnt;
    }
    Tree[Point].Sum=Tree[Point<<1].Sum+Tree[Point<<1|1].Sum;
}
void PushDn(LL Point)
{
    LL Maxn=max(Tree[Point<<1].MaxA,Tree[Point<<1|1].MaxA);
    if(Tree[Point<<1].MaxA==Maxn){
        UpDate(Point<<1,Tree[Point].Add_A,Tree[Point].Add_B,Tree[Point].Add_A1,Tree[Point].Add_B1);
    }else{
        UpDate(Point<<1,Tree[Point].Add_A1,Tree[Point].Add_B1,Tree[Point].Add_A1,Tree[Point].Add_B1);
    }
    if(Tree[Point<<1|1].MaxA==Maxn){
        UpDate(Point<<1|1,Tree[Point].Add_A,Tree[Point].Add_B,Tree[Point].Add_A1,Tree[Point].Add_B1);
    }else{
        UpDate(Point<<1|1,Tree[Point].Add_A1,Tree[Point].Add_B1,Tree[Point].Add_A1,Tree[Point].Add_B1);
    }
    Tree[Point].Add_A=Tree[Point].Add_A1=Tree[Point].Add_B=Tree[Point].Add_B1=0;
}
void Build(LL Point,LL L,LL R)
{
    Tree[Point].L=L,Tree[Point].R=R;
    if(L==R){
        Tree[Point].Sum=Tree[Point].MaxA=Tree[Point].MaxB=Read();
        Tree[Point].SecMaxA=INF;
        Tree[Point].Cnt=1;
    }else{
        LL Mid=(L+R)>>1;
        Build(Point<<1,L,Mid);
        Build(Point<<1|1,Mid+1,R);
        PushUp(Point);
    }
}
void ModifyAdd(LL Point,LL L,LL R,LL Key)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        UpDate(Point,Key,Key,Key,Key);
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1;
        if(L<=Mid)ModifyAdd(Point<<1,L,R,Key);
        if(R>=Mid+1)ModifyAdd(Point<<1|1,L,R,Key);
        PushUp(Point);
    }
}
void ModifyMin(LL Point,LL L,LL R,LL Key)
{
    if(Tree[Point].L>R||Tree[Point].R<L||Key>=Tree[Point].MaxA)return;
    if(L<=Tree[Point].L&&R>=Tree[Point].R&&Key>Tree[Point].SecMaxA){
        UpDate(Point,Key-Tree[Point].MaxA,Key-Tree[Point].MaxA,0,0);
    }else{
        PushDn(Point);
        ModifyMin(Point<<1,L,R,Key);
        ModifyMin(Point<<1|1,L,R,Key);
        PushUp(Point);
    }
}
LL QueryAdd(LL Point,LL L,LL R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].Sum;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=0;
        if(L<=Mid)Ans+=QueryAdd(Point<<1,L,R);
        if(R>=Mid+1)Ans+=QueryAdd(Point<<1|1,L,R);
        return Ans;
    }
}
LL QueryMaxA(LL Point,LL L,LL R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].MaxA;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=INF;
        if(L<=Mid)Ans=max(Ans,QueryMaxA(Point<<1,L,R));
        if(R>=Mid+1)Ans=max(Ans,QueryMaxA(Point<<1|1,L,R));
        return Ans;
    }
}
LL QueryMaxB(LL Point,LL L,LL R)
{
    if(L<=Tree[Point].L&&R>=Tree[Point].R){
        return Tree[Point].MaxB;
    }else{
        PushDn(Point);
        LL Mid=(Tree[Point].L+Tree[Point].R)>>1,Ans=INF;
        if(L<=Mid)Ans=max(Ans,QueryMaxB(Point<<1,L,R));
        if(R>=Mid+1)Ans=max(Ans,QueryMaxB(Point<<1|1,L,R));
        return Ans;
    }
}
int main()
{
    N=Read(),M=Read();
    Build(1,1,N);
    for(LL i=1;i<=M;i++){
        Flag=Read(),A=Read(),B=Read();
        if(Flag==1)ModifyAdd(1,A,B,Read());
        if(Flag==2)ModifyMin(1,A,B,Read());
        if(Flag==3)printf("%lld\n",QueryAdd(1,A,B));
        if(Flag==4)printf("%lld\n",QueryMaxA(1,A,B));
        if(Flag==5)printf("%lld\n",QueryMaxB(1,A,B));
    }
    return 0;
}