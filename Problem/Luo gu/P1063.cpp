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

const int maxn = 205;

struct node {
    int f, e;
} q[maxn];
int n, ans, dp[maxn][maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        q[i].f = read();
        if (i == 1) q[n].e = q[i].f;
        else q[i - 1].e = q[i].f;
    }
    for (int i = 1; i <= n - 1; i++) q[i + n] = q[i];
    int lim = 2 * n - 1;
    for (int len = 2; len <= lim; len++) {
        for (int l = 1, r = len; r <= lim; l++, r++) {
            for (int mid = l; mid <= r - 1; mid++) {
                dp[l][r] = std::max(dp[l][r], dp[l][mid] + dp[mid + 1][r] + q[l].f * q[r].e * q[mid].e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, dp[i][i + n - 1]);
    }
    return printf("%d\n", ans), 0;
}