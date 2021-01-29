#include <bits/stdc++.h>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

long long n;

int main() {
    n = read();
    if (n <= 1) puts("-1");
    else printf("%lld %lld %lld\n", n, n + 1, n * (n + 1));
    return 0;
}