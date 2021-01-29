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

const int maxn = 17;

int n, lim, ans;
int s[maxn], dp[maxn][1 << maxn];

signed main() {
    n = read(), lim = read();
    for (int i = 1; i <= n; i++) s[i] = read();
    for (int i = 1; i <= n; i++) {
        dp[i][1 << (i - 1)] = 1;
    }   
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j][i] || !(i & (1 << (j - 1)))) continue;
            int lst = i - (1 << (j - 1));
            for (int k = 1; k <= n; k++) {
                if (k == j || !(lst & (1 << (k - 1)))) continue;
                if (std::abs(s[j] - s[k]) > lim) dp[j][i] += dp[k][lst];
            }
        }
    }
    for (int i = 1; i <= n; i++) ans += dp[i][(1 << n) - 1];
    return printf("%lld\n", ans), 0;
}