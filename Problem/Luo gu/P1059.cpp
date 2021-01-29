#include<iostream>
#include<algorithm>

using namespace std;

int num[1001],cnt[101];
int n,k,tail=1;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		if(num[k]!=1){
			cnt[tail]=k;
			tail++;
			num[k]=1;
		}
		else continue;
	}
	sort(cnt+1,cnt+tail);
	cout<<tail-1<<endl;
	for(int i=1;i<tail;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 