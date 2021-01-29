#include<bits/stdc++.h>

const int maxn = 3.2e4 + 5, maxm = 65;
int n, m, fin, ans, dp[maxn];
bool vis[maxm];
struct node {
    int v, w, s[2], cnt;
} q[maxm];

inline long long read() {
    char str = getchar(); long long ans = 0, tag = 1;
    while (str < '0' || str > '9') { tag = str == '-' ? -1 : 1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = ans * 10 + str - '0'; str = getchar(); }
    return ans * tag;
}
inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        q[i].v = read(), q[i].w = q[i].v * read(), fin = read();
        if (fin) q[fin].s[q[fin].cnt++] = i, vis[i] = true;
    }   
    for (int i = 1; i <= m; i++) {
        if (vis[i]) continue;
        for (int j = n; j >= q[i].v; j--) {
            dp[j] = max(dp[j], dp[j - q[i].v] + q[i].w);
            if (q[i].cnt >= 1) {
                if (j >= q[i].v + q[q[i].s[0]].v) {
                    dp[j] = max(dp[j], dp[j - (q[i].v + q[q[i].s[0]].v)] + q[i].w + q[q[i].s[0]].w);
                }
            }
            if (q[i].cnt == 2) {
                if (j >= q[i].v + q[q[i].s[1]].v) {
                    dp[j] = max(dp[j], dp[j - (q[i].v + q[q[i].s[1]].v)] + q[i].w + q[q[i].s[1]].w);
                }
                if (j >= q[i].v + q[q[i].s[0]].v + q[q[i].s[1]].v) {
                    dp[j] = max(dp[j], dp[j - (q[i].v + q[q[i].s[0]].v + q[q[i].s[1]].v)] + q[i].w + q[q[i].s[0]].w + q[q[i].s[1]].w);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) ans = max(ans, dp[i]);
    return printf("%d\n", ans), 0;
}