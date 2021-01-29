#include <bits/stdc++.h>

const int maxn = 2e5 + 5;
const int inf = 0x7f7f7f7f;

char c;
int pos[4][maxn], cnt[4];
int n, k, ans = inf, str[maxn], sum[maxn];
int l, r;

inline int value();

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        str[i] = c == 'J' ? 1 : (c == 'O' ? 2 : 3);
        pos[str[i]][++cnt[str[i]]] = i;
        sum[i] = sum[i - 1] + (str[i] == 2);
    }
    if (cnt[1] < k || cnt[2] < k || cnt[3] < k) return puts("-1"), 0;
    l = k, r = 1;
    for (l; l <= cnt[1]; l++) {
        while (sum[pos[3][r]] - sum[pos[1][l]] < k && r <= cnt[3] && r <= cnt[3] - k + 1) r++;
        if (r == cnt[3] + 1 || r > cnt[3] - k + 1) break;
        ans = std::min(ans, value());
    }
    return printf("%d\n", ans == inf ? -1 : ans), 0;
}

inline int value() {
    int ans = 0;
    ans += pos[1][l] - pos[1][(l - k + 1)] - 1 - (k - 2);
    ans += pos[3][(r + k - 1)] - pos[3][r] - 1 - (k - 2);
    ans += pos[3][r] - pos[1][l] - 1 - k;
    return ans;
}