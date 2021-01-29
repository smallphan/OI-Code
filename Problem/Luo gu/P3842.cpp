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

const int maxn = 2e4 + 5;

int n, l[maxn], r[maxn];
int dp[maxn][2];

inline int dis(int, int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        l[i] = read(), r[i] = read();
    }
    dp[1][0] = dis(1, r[1]) + dis(l[1], r[1]), dp[1][1] = dis(1, r[1]);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = std::min(dp[i - 1][0] + dis(l[i - 1], r[i]), dp[i - 1][1] + dis(r[i - 1], r[i])) + dis(l[i], r[i]) + 1;
        dp[i][1] = std::min(dp[i - 1][0] + dis(l[i - 1], l[i]), dp[i - 1][1] + dis(r[i - 1], l[i])) + dis(l[i], r[i]) + 1;
    }
    return printf("%d\n", std::min(dp[n][0] + dis(l[n], n), dp[n][1] + dis(r[n], n))), 0;
}

inline int dis(int a, int b) {
    return std::abs(a - b);
}