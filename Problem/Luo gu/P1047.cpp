#include<iostream>

using namespace std;

int L,M,qj[1000001],x,y,sum;

int main()
{
	cin>>L>>M;
	int i,j;
	for(i=1;i<=M;i++){
		cin>>x>>y;
		for(j=x;j<=y;j++){
			qj[j]=1;
		}
	}
	for(i=0;i<=L;i++){
		if(qj[i]!=1)
			sum++;
	}
	cout<<sum;
	return 0;
}