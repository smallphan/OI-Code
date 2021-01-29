#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
	int x,y;
};
int H[105][105],R,C;
int Len,DP[105][105],Ans=-999;
Node Coor[10005];
int Dx[5]={0,1,-1,0,0},Dy[5]={0,0,0,1,-1};

bool CMP(Node A,Node B)
{
	return H[A.x][A.y]>H[B.x][B.y];
}
int main()
{
	cin>>R>>C;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin>>H[i][j];
			Coor[++Len].x=i;
			Coor[Len].y=j;	
		}
	} 
	sort(Coor+1,Coor+Len+1,CMP);
	for(int i=1;i<=Len;i++){
		int X=Coor[i].x;
		int Y=Coor[i].y;
		DP[X][Y]=1;
		for(int j=1;j<=4;j++){
			int XX=X+Dx[j];
			int YY=Y+Dy[j];
			if(XX>=1&&XX<=R&&YY>=1&&YY<=C&&H[XX][YY]>H[X][Y]){
				DP[X][Y]=max(DP[X][Y],DP[XX][YY]+1);
			}
		}
	}
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			Ans=max(Ans,DP[i][j]);
		}
	}
	cout<<Ans<<endl;
	return 0;
} 