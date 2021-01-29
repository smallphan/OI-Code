#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char Char[300];
int Ans_B,Ans_G;

int main()
{
    gets(Char);
    for(int i=0;i<strlen(Char);i++){
        if(Char[i]=='b'||Char[i+1]=='o'||Char[i+2]=='y'){
             Ans_B++;
        }
        if(Char[i]=='g'||Char[i+1]=='i'||Char[i+2]=='r'||Char[i+3]=='l'){
            Ans_G++;
        }
    }
    cout<<Ans_B<<endl<<Ans_G;
    return 0;
}