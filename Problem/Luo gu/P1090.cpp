#include<iostream>
#include<cstdio>
using namespace std;

struct Node{
    int Num[100005],HeapSize;
    void ShiftUp(int Point){
        if(Point==1)return;
        if(Num[Point]<Num[Point>>1]){
            swap(Num[Point],Num[Point>>1]);
            ShiftUp(Point>>1);
        }
    }
    void ShiftDn(int Point){
        int Mark=Point;
        if((Point<<1)<=HeapSize&&Num[(Point<<1)]<Num[Mark])Mark=(Point<<1);
        if((Point<<1|1)<=HeapSize&&Num[(Point<<1|1)]<Num[Mark])Mark=(Point<<1|1);
        if(Mark==Point)return;
        swap(Num[Mark],Num[Point]);
        ShiftDn(Mark);
    }
    int Top(){
        return Num[1];
    }
    void Pop(){
        Num[1]=Num[HeapSize--];
        ShiftDn(1);
    }
    bool Empty(){
        return !HeapSize;
    }
    int Size(){
        return HeapSize;
    }
    void Push(int X){
        Num[++HeapSize]=X;
        ShiftUp(HeapSize);
    }
}Fruit;
int N,X,Ans;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    N=Read();
    for(int i=1;i<=N;i++){
        X=Read();
        Fruit.Push(X);
    }
    for(int i=1;i<=N-1;i++){
        int x=Fruit.Top();Fruit.Pop();
        int y=Fruit.Top();Fruit.Pop();
        Ans+=x+y;
        Fruit.Push(x+y);
    }
    printf("%d\n",Ans);
    return 0;
}