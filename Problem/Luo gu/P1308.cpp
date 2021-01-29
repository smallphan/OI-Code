#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char word[11];
char passage[1000010];
int len_w,len_p;
int ad,ans;
int a,j;

bool check(char a,char b)
{
	char x,y;
	x=b-32;
	y=b+32;
	if(a==x||a==b||a==y)return true;
	return false;
}
int main()
{
	gets(word);
	gets(passage);
	len_w=strlen(word);
	len_p=strlen(passage);
	for(int i=0;i<=len_p-len_w;i++){
		a=i;
		while(check(word[j],passage[a])&&j<len_w){
			j++;
			a++;
		}
		if(j==len_w){
			if(ans==0){
				ad=i;
			}
			ans++;
		}
		j=0;
	}
	if(ans==0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<' '<<ad;
	return 0;
}