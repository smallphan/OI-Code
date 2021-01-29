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

const int maxn = 100 + 5;
const int lim = 50;

int n, tag = 3, ans, seq[maxn];
bool vis[3][maxn];

void dfs(int);

int main() {
    scanf("%d", &n);
    dfs(1);
    return printf("%d\n", ans), 0;
}

void dfs(int now) {
    if (now == n + 1) {
        ans++;
        if (tag) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", seq[i]);
            }
            tag--, puts("");
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (vis[0][i] || vis[1][i + now + lim] || vis[2][i - now + lim]) continue;
            vis[0][i] = vis[1][i + now + lim] = vis[2][i - now + lim] = true;
            seq[now] = i;
            dfs(now + 1);
            vis[0][i] = vis[1][i + now + lim] = vis[2][i - now + lim] = false;
        }
    }
}