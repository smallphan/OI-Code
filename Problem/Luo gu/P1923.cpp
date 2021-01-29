#include<iostream>
#include<cstdio>
#define Lson (Point<<1)
#define Rson (Point<<1|1)
#define Dad (Point>>1)

using namespace std;

const int Maxn=5e6+5;
struct Node{
    int Num[Maxn],HeapSize;
    void ShiftUp(int Point){
        if(Point==1)return;
        if(Num[Point]<Num[Dad]){
            swap(Num[Point],Num[Dad]);
            ShiftUp(Dad);
        }
    }
    void ShiftDn(int Point){
        int Mark=Point;
        if(Lson<=HeapSize&&Num[Lson]<Num[Mark])Mark=Lson;
        if(Rson<=HeapSize&&Num[Rson]<Num[Mark])Mark=Rson;
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
}Heap;
int N,K,Num;

inline int Read()
{
    int Ans=0,Flag=1;char X=getchar();
    while(X<'0'||X>'9'){if(X=='-')Flag=-1;X=getchar();}
    while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
    return Ans*Flag;
}
int main()
{
    N=Read(),K=Read();
    for(int i=1;i<=N;i++){
        Num=Read();
        Heap.Push(Num);
    }
    while(K--){
        Heap.Pop();
    }
    cout<<Heap.Top()<<endl;
    return 0;
}