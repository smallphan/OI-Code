#include<iostream>
#include<cstring>
#define LL long long

using namespace std;

const LL Mod=1e9+7;
struct Matrix{
	LL Data[105][105];
}Ans,a;
LL n,k;

Matrix Mul(Matrix a,Matrix b,LL n,LL m,LL r)
{
	Matrix c;
	memset(c.Data,0,sizeof(c.Data));	
	for(LL k=1;k<=m;k++){
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=r;j++){
				c.Data[i][j]=(c.Data[i][j]+(a.Data[i][k]*b.Data[k][j])%Mod)%Mod;
			}
		}
	}
	return c;
}
Matrix QuickPow(Matrix a,LL k,LL n)
{
	Matrix c;
	memset(c.Data,0,sizeof(c.Data));
	for(LL i=1;i<=n;i++){
		c.Data[i][i]=1;
	}
	while(k){
		if(k&1)c=Mul(c,a,n,n,n);
		k>>=1;
		a=Mul(a,a,n,n,n);
	}
	return c;
}
int main()
{
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			cin>>a.Data[i][j];
		}
	}
	Ans=QuickPow(a,k,n);
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			cout<<Ans.Data[i][j]<<' ';
		}
		cout<<endl;
	}
} 