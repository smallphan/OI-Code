#include<cstdio>
#include<iostream>

using namespace std;

typedef unsigned long long ull;
ull n;

int main(){
    scanf("%lld",&n);
    cout<<(((n*(n-1)/2)*(n-2)/3)*(n-3)/4)<<endl;
    return 0;
}