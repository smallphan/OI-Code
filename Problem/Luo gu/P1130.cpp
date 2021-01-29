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

const int maxn = 2e3 + 5;
const int inf = 0x7f7f7f7f;

int n, m, ans = inf, dp[maxn][maxn];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[1][i] += std::min(dp[m][i - 1], dp[1][i - 1]);
        for (int j = 2; j <= m; j++) {
            dp[j][i] += std::min(dp[j][i - 1], dp[j - 1][i - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        ans = std::min(ans, dp[i][n]);
    }
    return printf("%d\n", ans), 0;
}