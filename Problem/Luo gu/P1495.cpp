#include<iostream>
#define LL long long 

using namespace std;

LL x,y,n;
LL A[15],B[15],ModSum=1,Ans; 

void EXGCD(LL a,LL b,LL &x,LL &y)
{
	if(!b){
		x=1;
		y=0;
		return;
	}
	EXGCD(b,a%b,x,y);
	LL Num=x;
	x=y;
	y=Num-(a/b)*y;
}
int main()
{
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>A[i]>>B[i];
		ModSum*=A[i];
	}
	for(LL i=1;i<=n;i++){
		LL ModNow=ModSum/A[i];
		x=y=0;
		EXGCD(ModNow,A[i],x,y);
		while(x<0){
			x+=A[i];
		}
		x%=A[i];
		Ans+=ModNow*B[i]*x;
	}
	Ans%=ModSum;
	cout<<Ans<<endl;
	return 0;
}