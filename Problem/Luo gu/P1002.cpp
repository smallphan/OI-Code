#include<iostream>

using namespace std;

int a[51][51],n,m,x,y,sum;
long long d[51][51];
int b[9]={0,1,2,2,1,-1,-2,-2,-1},c[9]={0,2,1,-1,-2,-2,-1,1,2};

int main()
{
	int i,j;
	cin>>n>>m>>x>>y;
	for(i=1;i<=8;i++){
		a[x+b[i]][y+c[i]]=1;
	}
	a[x][y]=1;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(a[i][j]==1){
				d[i][j]=0;
				continue;
			}
			else{
				if(i==0&&j==0){
					d[i][j]=1;
				}
				else if(i==0&&j!=0){
					d[i][j]=d[i][j-1];
				}
				else if(i!=0&&j==0){
					d[i][j]=d[i-1][j];
				}
				else{
					d[i][j]=d[i-1][j]+d[i][j-1];
				}
			}
		}
	}
	cout<<d[n][m]<<endl;
	return 0;
}