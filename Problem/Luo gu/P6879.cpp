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

typedef long long ll;

const int maxn = 200 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, len, x[maxn], t[maxn];
ll dp[maxn][maxn][maxn][2];

inline void chkmin(ll&, ll);

int main() {
    memset(dp, 0x3f, sizeof(dp));
    n = read(), len = read(), x[n + 1] = len;
    for (int i = 1; i <= n; i++) x[i] = read();
    for (int i = 1; i <= n; i++) t[i] = read();
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    int find = 0, ans = 0;
    for (int l = 0; l <= n; l++) { // 左边到了 l
        for (int r = 0; r <= n - l; r++) { // 右边到了 r
            for (int k = 0; k <= l + r; k++) { // 当前采到了 k 张邮票
                for (int i = 0; i <= 1; i++) { // 当前在左边还是右边 i = 0 ==> 左边 | i = 1 ==> 右边
                    ll now = dp[l][r][k][i];
                    if (now == inf) continue;
                    ans = std::max(ans, k);
                    if (l + r + 1 <= n) {
                        if (!i) {
                            find = (now + x[n + 1 - l] - x[n - l] <= t[n - l]);
                            chkmin(dp[l + 1][r][k + find][0], now + x[n + 1 - l] - x[n - l]);
                            find = (now + len - x[n + 1 - l] + x[r + 1] <= t[r + 1]);
                            chkmin(dp[l][r + 1][k + find][1], now + len - x[n + 1 - l] + x[r + 1]);
                        } else {
                            find = (now + x[r + 1] - x[r] <= t[r + 1]);
                            chkmin(dp[l][r + 1][k + find][1], now + x[r + 1] - x[r]);
                            find = (now + x[r] + len - x[n - l] <= t[n - l]);
                            chkmin(dp[l + 1][r][k + find][0], now + x[r] + len - x[n - l]);
                        }
                    }
                }
            }
        }
    }
    return printf("%d\n", ans), 0;
}

inline void chkmin(ll& a, ll b) {
    a = a < b ? a : b;
}