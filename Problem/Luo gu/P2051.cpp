#include <cstdio>

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

using namespace std;

typedef long long li;

const li maxn = 105;
const li mod = 9999973;

li n, m, ans, dp[maxn][maxn][maxn];

inline li C(li);

int main() {
    n = read(), m = read();
    dp[0][0][0] = 1;
    for (li i = 1; i <= n; i++) {
        for (li j = 0; j <= m; j++) {
            for (li k = 0; k <= m - j; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k >= 1) dp[i][j][k] += dp[i - 1][j + 1][k - 1] * (j + 1);
                if (j >= 1) dp[i][j][k] += dp[i - 1][j - 1][k] * (m - j - k + 1);
                if (k >= 2) dp[i][j][k] += dp[i - 1][j + 2][k - 2] * ((j + 1) * (j + 2) / 2);
                if (k >= 1) dp[i][j][k] += dp[i - 1][j][k - 1] * j * (m - j - k + 1);
                if (j >= 2) dp[i][j][k] += dp[i - 1][j - 2][k] * C(m - j - k + 2);
                dp[i][j][k] %= mod;
            }
        }
    }
    for (li i = 0; i <= m; i++) {
        for (li j = 0; j <= m; j++) {
            ans = (ans + dp[n][i][j]) % mod;
        }
    }
    printf("%lld\n", (ans + mod) % mod);
    return 0;
}

inline li C(li now) {
    return (now * (now - 1) / 2) % mod;
}