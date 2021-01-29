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

const int maxn = 13;
const int mod = 1e8;

int n, m;
li map[maxn], dp[maxn][1 << maxn], ans;

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[i] = map[i] << 1;
            map[i] += 1 ^ read();
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int now = 0; now < (1 << m); now++) {
            if (now & ((now << 1) | (now >> 1) | map[i])) continue;
            for (int lst = 0; lst < (1 << m); lst++) {
                if (lst & (now | (lst << 1) | (lst >> 1))) continue;
                dp[i][now] += dp[i - 1][lst];
            }
        }
    }
    for (int k = 0; k < (1 << m); k++) ans += dp[n][k];
    printf("%lld\n", ans % mod);
    return 0;
}