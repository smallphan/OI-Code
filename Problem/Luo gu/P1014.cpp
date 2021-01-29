#include<iostream>

using namespace std;

long a=0;
int cnt;
long n,t;
int fz,fm;//fz·Ö×Ó fm·ÖÄ¸ 

int main()
{
	cin>>n;
	for(int i=1;i<=10000000;i++){
		a+=i;
		cnt++;
		if(n==a||n<a){
			a-=i;
			break;
		}
	}
	if(cnt%2==0){
		fz=1;
		fm=cnt;
		for(int i=a+1;i<=n-1;i++){
			fz++;
			fm--;
		}
	} 
	else{
		fz=cnt;
		fm=1;
		for(int i=a+1;i<=n-1;i++){
			fz--;
			fm++;
		}
	}
	cout<<fz<<'/'<<fm<<endl;
	return 0;
}