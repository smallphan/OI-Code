#include <bits/stdc++.h>

#define int long long

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

const int maxn = 1e3 + 5;

int n, dp[maxn];

int prime[maxn], cnt;
bool check[maxn];

inline void init();

signed main() {
    n = read(), init();
    dp[0] = 1;
    for (int i = 1; i <= cnt; i++) {
        for (int j = prime[i]; j <= n; j++) {
            dp[j] += dp[j - prime[i]];
        }
    }
    return printf("%lld\n", dp[n]), 0;
}

inline void init() {
    for (int i = 2; i <= n; i++) {
        if (!check[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            check[i * prime[j]] = true;
            if (!(i % prime[j])) break;
        }
    }
}