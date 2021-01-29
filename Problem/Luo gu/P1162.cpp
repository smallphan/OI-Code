#include<iostream>

using namespace std;

int pic[1001][1001];
int n,start_x,start_y;
bool vis[1001][1001];
int x_x[10]={0,0,0,1,-1},y_y[10]={0,1,-1,0,0};

void BFS(int x,int y)
{
	pic[x][y]=2;
	vis[x][y]=true;
	for(int q=1;q<=4;q++){
		int a=x+x_x[q],b=y+y_y[q];
		if(a<1||a>n||b<1||b>n)continue;
		if(!vis[a][b]&&pic[a][b]==0){
			BFS(a,b);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				cin>>pic[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i==1||i==n||j==1||j==n)&&pic[i][j]==0){
				BFS(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<2-pic[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}