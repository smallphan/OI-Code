#include<cstring>
#include<cstdio>

using namespace std;

char X[260];
int Check;

int main()
{
    gets(X);
    for(int i=0;i<strlen(X);i++){
        if(X[i]=='(')Check++;
        if(X[i]==')')Check--;
        if(Check<0){
            printf("NO\n");
            return 0;
        }
    }
    if(Check){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}