#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef double lf;

const int maxn = 16;
const int inf = 0x7f7f7f7f;
const lf eps = 1e-6;

struct node {
    lf x, y;

    inline lf operator - (const node& tmp) {
        return sqrt((x - tmp.x) * (x - tmp.x) + (y - tmp.y) * (y - tmp.y));
    }
} pos[maxn];

int n, que[maxn], cnt;
lf dp[maxn][1 << maxn], ans = inf;

int main() {
    memset(dp, inf, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &pos[i].x, &pos[i].y);
        dp[i][1 << (i - 1)] = (pos[i] - (node) { 0, 0 });
    }
    for (int s = 1; s < (1 << n); s++) {
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (((1 << (i - 1)) & s) == 0) que[++cnt] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (fabs(dp[i][s] - dp[0][0]) < eps) continue;
            for (int j = 1; j <= cnt; j++) {
                int now = que[j];
                dp[now][s | 1 << (now - 1)] = min(dp[now][s | 1 << (now - 1)], dp[i][s] + (pos[now] - pos[i]));
            }
        }
    }
    for (int i = 1; i <= n; i++) ans = min(ans, dp[i][(1 << n) - 1]);
    printf("%.2lf\n", ans);
    return 0;
}