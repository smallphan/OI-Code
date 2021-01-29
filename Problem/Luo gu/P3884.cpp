#include<iostream>
#include<cstring>

using namespace std;

const int Maxn=105;
struct Node{
	int Next,End;
}Edge[Maxn];
int First[Maxn],Len;
int N,A,B;
int Depth[Maxn],Breadth[Maxn],MaxDep=-9999,MaxBread=-9999;
int Dad[Maxn];

void AddEdge(int Start,int End)
{
	Edge[++Len].Next=First[Start];
	First[Start]=Len;
	Edge[Len].End=End;
}
void DFS(int Point,int Father)
{
	Dad[Point]=Father;
	Depth[Point]=Depth[Father]+1;
	MaxDep=max(MaxDep,Depth[Point]);
	Breadth[Depth[Point]]++;
	MaxBread=max(MaxBread,Breadth[Depth[Point]]);
	for(int i=First[Point];i!=-1;i=Edge[i].Next){
		if(Edge[i].End!=Father){
			DFS(Edge[i].End,Point);
		}
	}
}
int LCA(int A,int B)
{
	int AnsA=0,AnsB=0;
	while(Depth[A]>Depth[B]){
		A=Dad[A];
		AnsA++;
	}
	while(Depth[B]>Depth[A]){
		B=Dad[B];
		AnsB++;
	}
	while(A!=B){
		A=Dad[A];
		B=Dad[B];
		AnsA++;
		AnsB++;
	}
	return AnsA*2+AnsB;
}
int main()
{
	memset(First,-1,sizeof(First));	
	cin>>N;
	for(int i=1;i<=N-1;i++){
		cin>>A>>B;
		AddEdge(A,B);
		AddEdge(B,A);
	}
	cin>>A>>B;
	DFS(1,0);
	cout<<MaxDep<<endl<<MaxBread<<endl<<LCA(A,B)<<endl;
	return 0;
}
