#include<iostream>
#include<cstring>

using namespace std;

int Num[5],Len;
char Note[300],x;

int main()
{
    while(cin>>x){
        Note[++Len]=x;
    }
    for(int i=1;i<=Len/5;i++){
        int Pos=(i-1)*5+1;
        if(Note[Pos+3]>='a'&&Note[Pos+3]<='c'){
            Num[Note[Pos]-96]=Num[Note[Pos+3]-96];
        }else{
            Num[Note[Pos]-96]=(int)Note[Pos+3]-48;
        }
    }
    for(int i=1;i<=3;i++){
        cout<<Num[i]<<' ';
    }
}