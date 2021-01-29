#include<cstdio>

using namespace std;

int n;
int num[15]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};

int main(){
    scanf("%d",&n);
    printf("%d",num[n]);
    return 0;
}