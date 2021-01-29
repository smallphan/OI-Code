/**
 * 可以将问题转换成 有限背包 问题
 * 即从所有物品中选择 任意个数 等于 m 的方案数
 * 快乐求解
 **/

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

const int mod = 1e6 + 7;
const int maxn = 100 + 5;

int n, m, a[maxn], dp[maxn][maxn];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= std::min(j, a[i]); k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    return printf("%d\n", dp[n][m]), 0;
}