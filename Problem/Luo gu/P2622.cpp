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

const int maxn = 11;
const int maxm = 105;
const int inf = 0x7f7f7f7f;

int n, m;
int a[maxm][maxn], dp[1 << maxn];

int main() {
    n = read(), m = read();
    std::memset(dp, inf, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = read();
        }
    }
    dp[(1 << n) - 1] = 0;
    for (int i = (1 << n) - 1; i >= 0; i--) {
        for (int j = 1; j <= m; j++) {
            int now = i;
            for (int k = 1; k <= n; k++) {
                if (a[j][k] == 0) continue;
                if (a[j][k] == 1 && (now & (1 << (k - 1)))) now ^= (1 << (k - 1));
                if (a[j][k] == -1 && !(now & (1 << (k - 1)))) now ^= (1 << (k - 1));
            }
            dp[now] = std::min(dp[now], dp[i] + 1);
        }
    }
    return printf("%d\n", dp[0] == inf ? -1 : dp[0]), 0;
}