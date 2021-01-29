#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s[21],key='*',ans[25];
int key_num,num,len,bj;

void answer(int l,int r)
{
	if(r-l==1&&s[l]=='0'){
		cout<<0;
		return;
	}
	else{
		for(int i=r-1;i>=l;i--){
			ans[r-i]=s[i];
		}
		if(bj==0){
			int i=1;
			while(ans[i]=='0')i++;
			if(i>r)cout<<0;
			else{
				for(i;i<=r-l;i++){
					cout<<ans[i];
				}
			}
		}
		else if(bj==1){
			int i=r-l;
			while(ans[i]=='0')i--;
			if(i==0)cout<<0;
			else{
				for(int j=1;j<=i;j++){
					cout<<ans[j];
				}
			}
		}
		for(int i=0;i<=24;i++){
			ans[i]=0;
		}
	}
	return;
}
int main()
{
	cin>>s;
	num=strlen(s);
	for(int i=0;i<=20;i++){
		if(s[i]=='.'){
			key='.';
			key_num=i;
			break;
		}
		if(s[i]=='/'){
			key='/';
			key_num=i;
			break;
		}
		if(s[i]=='%'){
			key='%';
			key_num=i;
			break;
		}
	}
	switch(key){
		case '*':
			answer(0,num);
			break;
		case '.':
			answer(0,key_num);
			cout<<'.';
			bj=1;
 			answer(key_num+1,num);
			break;	
		case '/':
			answer(0,key_num);
			cout<<'/';
 			answer(key_num+1,num);
			break;	
		case '%':
			answer(0,num-1);
			cout<<'%';
	}
	return 0;
}