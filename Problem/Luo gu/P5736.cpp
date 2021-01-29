#include<cstdio>

using namespace std;

int n,num;
bool flag;

inline int read();

int main(){
    n=read();
    while(n--){
        num=read();
        if(num==1) continue;
        flag=true;
        for(int i=2;i*i<=num;i++){
            if(!(num%i)){
                flag=false;
                break;
            }
        }
        if(flag) printf("%d ",num);
    }
    return 0;
}

inline int read(){
    int ans=0,flag=1; char x=getchar();
    while(x<'0' || x>'9') {if(x=='-') flag=-1; x=getchar();}
    while(x>='0' && x<='9') {ans=ans*10+x-'0'; x=getchar();}
    return ans*flag;
}