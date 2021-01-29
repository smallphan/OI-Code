#include<iostream>
#include<algorithm>

using namespace std;

int num[10]={0,1,2,3,4,5,6,7,8,9};
int a,b,c;
bool pd=true;

int hb(int i)
{
	return num[i]*100+num[i+1]*10+num[i+2];
}
void check()
{
	int A=hb(1),B=hb(4),C=hb(7);
	if(A*b==B*a&&B*c==C*b){
		pd=false;
		cout<<A<<' '<<B<<' '<<C<<endl;
	}
}
int main()
{
	cin>>a>>b>>c;
	do{
		check();
	}while(next_permutation(num+1,num+10));
	if(pd)cout<<"No!!!"<<endl;
	return 0;
}
