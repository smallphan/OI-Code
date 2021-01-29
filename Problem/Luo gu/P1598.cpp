#include<iostream>
#include<cstring>

using namespace std;

int maxn,a[30]={0};
string b;
char c;

int main()
{
    for(int i=1;i<=4;i++){getline(cin,b);for(int j=0;j<b.length();j++)if(b[j]>='A'&&b[j]<='Z'){c=b[j]-65;a[c]++;}}
	
	maxn=a['A'-65];
    
	for(char c='B';c<='Z';c++)if (a[c-65]>maxn) maxn=a[c-65];
    
	for(int i=maxn;i>0;i--){for(char c='A';c<='Z';c++)if(a[c-65]>=i) {cout<<"* ";   a[c-65]--;}else cout<<"  ";cout<<endl;}
    
	for(char c='A';c<='Z';c++)cout<<c<<" ";
    
	return 0;
}