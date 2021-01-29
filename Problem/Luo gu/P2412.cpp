#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>

using namespace std;

const int Maxn=50005;
struct Node{
	string A,B;
}WordA[Maxn],WordB[Maxn];
int ST[Maxn][30],Log[Maxn];
map<string,int>Pos;
string STR;
int N,M,L,R;

inline int Read()
{
	int Ans=0;char X=getchar();
	while(X<'0'||X>'9')X=getchar();
	while(X>='0'&&X<='9'){Ans=Ans*10+X-'0';X=getchar();}
	return Ans;
}
bool CMP(Node A,Node B)
{
	return A.B<B.B;
}
void Init()
{
	for(int i=1;i<=N;i++)Log[i]=Log[i-1]+(1<<(Log[i-1]+1)==i);
	for(int j=1;j<=Log[N];j++){
		for(int i=1;i+(1<<j)-1<=N;i++){
			int k=i+(1<<(j-1));
			ST[i][j]=max(ST[i][j-1],ST[k][j-1]);
		}
	}
}
int main()
{
	N=Read(),M=Read();
	for(int i=1;i<=N;i++){
		cin>>STR;
		WordA[i].A=WordB[i].A=STR;
		for(int j=0;j<=STR.length();j++){
			if(STR[j]>='A'&&STR[j]<='Z')STR[j]=STR[j]-'A'+'a';
			else STR[j]=STR[j];
		}
		WordA[i].B=WordB[i].B=STR;
	}
	sort(WordB+1,WordB+1+N,CMP);
	for(int i=1;i<=N;i++){
		Pos[WordB[i].B]=i;
	}
	for(int i=1;i<=N;i++){
		ST[i][0]=Pos[WordA[i].B];
	}
	Init();
	while(M--){
		L=Read(),R=Read();
		int j=Log[R-L+1],k=R-(1<<j)+1;
		cout<<WordB[max(ST[L][j],ST[k][j])].A<<endl;
	}
	return 0;
}