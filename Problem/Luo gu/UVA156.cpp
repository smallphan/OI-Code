#include<map>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

map<string,int>cnt;
vector<string>words;
int n;
string str;

string standard(const string&);

int main(){
    while(cin>>str){
        if(str[0]=='#') break;
        words.push_back(str);
        string ans=standard(str);
        if(!cnt.count(ans)) cnt[ans]=0;
        cnt[ans]++;
    }
    vector<string>ans;
    for(int i=0;i<words.size();i++){
        if(cnt[standard(words[i])]==1) ans.push_back(words[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

string standard(const string& str){
    string ans=str;
    for(int i=0;i<ans.length();i++){
        ans[i]=tolower(ans[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}