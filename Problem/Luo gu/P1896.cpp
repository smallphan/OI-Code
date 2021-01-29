#include <cstdio>

using namespace std;

typedef long long li;

const int maxn = 10;

int n, m;
li sum[1 << maxn], ans;
li dp[maxn][maxn * maxn][1 << maxn];

inline void init();
inline int get(int);

int main() {
    scanf("%d %d", &n, &m), init();
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int now = 0; now < (1 << n); now++) {
            if (now & ((now << 1) | (now >> 1))) continue;
            for (int lst = 0; lst < (1 << n); lst++) {
                if (lst & ((lst << 1) | (lst >> 1)) || now & (lst | (lst << 1) | (lst >> 1))) continue;
                for (int j = sum[now]; j <= m; j++) {
                    dp[i][j][now] += dp[i - 1][j - sum[now]][lst];
                }
            }
        }
    }
    for (int k = 0; k < (1 << n); k++) {
        ans += dp[n][m][k];
    }
    printf("%lld\n", ans);
    return 0;
}

inline void init() {
    for (int k = 0; k < (1 << n); k++) {
        sum[k] = get(k);
    }
}

inline int get(int num) {
    int tot = 0;
    while (num && ++tot) num -= num & (-num);
    return tot;
}