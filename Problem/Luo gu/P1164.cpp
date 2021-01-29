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

const int maxn = 105;
const int maxm = 1e4 + 5;

int n, m, val, dp[maxm];

int main() {
    n = read(), m = read(), dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        val = read();
        for (int j = m; j >= val; j--) {
            dp[j] += dp[j - val];
        }
    }
    return printf("%d\n", dp[m]), 0;
}