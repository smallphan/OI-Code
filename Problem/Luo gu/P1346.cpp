#include<iostream>
#include<algorithm>

using namespace std;

int N,Start,End;
int Pic[101][101];

int main()
{
	cin>>N>>Start>>End;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			Pic[i][j]=i==j?0:0xf777;
		}
	}
	for(int i=1;i<=N;i++){
		int X;cin>>X;
		for(int j=1;j<=X;j++){
			int Y;cin>>Y;
			if(j==1){
				Pic[i][Y]=0;
			}
			else{
				Pic[i][Y]=1;
			}
		}
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(Pic[i][k]+Pic[k][j]<Pic[i][j]){
					Pic[i][j]=Pic[i][k]+Pic[k][j];
				}
			}
		}
	}
	if(Pic[Start][End]==0xf777){
		cout<<-1<<endl;
		return 0;
	}
	cout<<Pic[Start][End];
	return 0;
} 