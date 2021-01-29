#include<cstdio>

using namespace std;

int mod;
bool flag=true;

bool I(int);
bool II(int);
bool III(int);

int main(){
    scanf("%d",&mod);
    for(int i=1e4;i<=3e4;i++){
        if(I(i) && II(i) && III(i)){
            printf("%d\n",i);
            flag=false;
        }
    }
    if(flag) printf("No\n");
    return 0;
}

bool I(int num){
    return !((num/100)%mod);
}
bool II(int num){
    return !(((num/10)-(num/10000*1000))%mod);
}
bool III(int num){
    return !((num%1000)%mod);
}