#include<iostream>
#include<cstring>
#define LL long long 

using namespace std;

struct Matrix{
	LL Data[505];
	void Init(){
		memset(Data,0,sizeof(Data));
	}
};
LL n,m,d,k;

inline LL Coor(LL i,LL j){return (j-i+1)>0?(j-i+1):(j-i+6);}
Matrix MatInit(LL Dis,LL n)
{
	Matrix c;
	c.Init();
	for(LL i=1;i<=Dis+1;i++){
		c.Data[i]=1;
	}
	for(LL i=n;i>n-Dis;i--){
		c.Data[i]=1;
	}
	return c;
}
Matrix Mul(Matrix a,Matrix b,LL n,LL Mod)
{
	Matrix c;
	c.Init();
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			c.Data[i]=(c.Data[i]+(a.Data[j]*b.Data[Coor(i,j)])%Mod)%Mod;
		}
	}
	return c;
}
Matrix Pow(Matrix a,LL n,LL k,LL Mod)
{
	Matrix c;
	c.Init();
	c.Data[1]=1;
	while(k){
		if(k&1)c=Mul(c,a,n,Mod);
		k>>=1;
		a=Mul(a,a,n,Mod);
	}	
	return c;
}
int main()
{
	while(cin>>n>>m>>d>>k){
		Matrix Num,Ans;
		Num.Init();
		Ans.Init();
		for(LL i=1;i<=n;i++){
			cin>>Num.Data[i];
		}
		Ans=MatInit(d,n);
		Ans=Pow(Ans,n,k,m);
		Ans=Mul(Num,Ans,n,m);
		for(LL i=1;i<=n;i++){
			cout<<Ans.Data[i]<<' ';
		}
	}
} 
