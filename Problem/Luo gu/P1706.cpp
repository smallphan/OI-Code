#include<iostream>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
    int n,i,j=1,k;
    cin>>n;
    for(i=1;i<=n;i++){
		a[i]=n-i+1;j*=i;
	}
    for(i=1;i<=j;i++){
		next_permutation(a+1,a+n+1);
    	for(k=1;k<=n;k++)
    		cout<<"    "<<a[k];
    	cout<<endl;
    }
    return 0;
}