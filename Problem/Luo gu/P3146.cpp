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

const int maxn = 250 + 5;

int n, ans, dp[maxn][maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) dp[i][i] = read();
    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            for (int mid = l; mid < r; mid++) {
                if (dp[l][mid] == dp[mid + 1][r]) {
                    dp[l][r] = std::max(dp[l][r], dp[l][mid] + 1);
                    ans = std::max(ans, dp[l][r]);
                }
            }
        }
    }
    return printf("%d\n", ans), 0;
}