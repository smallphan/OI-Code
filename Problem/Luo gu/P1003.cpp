/*先将所有数据读入 从最后n块地毯开始（最后的地毯在最上面） 写一个函数判断点是否在范围内
如果有 输出并return 0 如果没有 一直循环完毕 时间复杂度最大为O（n） */ 
#include<iostream>

using namespace std;

int n,num[10001][5];
int a,b;
int x,y;
bool ans;

bool check(int i)
{
	if(a>=num[i][1]&&a<=num[i][3]&&b>=num[i][2]&&b<=num[i][4])
	return true;
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i][1]>>num[i][2]>>x>>y;
		num[i][3]=num[i][1]+x;
		num[i][4]=num[i][2]+y;
	}
	cin>>a>>b;
	for(int i=n;i>=1;i--){
		if(check(i)){
			cout<<i;
			ans=true;
			break;
		}
	}
	if(!ans)cout<<-1;
	return 0;
} 