#include <bits/stdc++.h>

#define pb push_back

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

const int maxn = 1e5 + 5;

int n, s, q, u, v;
int up[maxn][30], dep[maxn], lg[maxn];
std::vector<int> edge[maxn];

void dfs(int, int);
inline void init();
inline int lca(int, int);

int main() {
    n = read(), s = read(), q = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        edge[u].pb(v), edge[v].pb(u);
    }
    dfs(s, s), init();
    while (q--) {
        u = read(), v = read();
        printf("lca [%d, %d] == %d\n", u, v, lca(u, v));
    }
    return 0;
}

void dfs(int now, int fat) {
    up[now][0] = fat;
    dep[now] = dep[fat] + 1;
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i];
        if (end != fat) dfs(end, now);
    }
}

inline void init() {
    for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int s = 1; s <= lg[n]; s++) {
        for (int i = 1; i <= n; i++) {
            up[i][s] = up[up[i][s - 1]][s - 1];
        }
    }
}

inline int lca(int u, int v) {
    if (u == v) return u;
    if (dep[u] < dep[v]) std::swap(u, v);
    while (dep[u] > dep[v]) u = up[u][lg[dep[u] - dep[v]]];
    if (u == v) return u;
    for (int s = lg[dep[u]]; s >= 0; s--) {
        if (up[u][s] != up[v][s]) {
            u = up[u][s], v = up[v][s];
        }
    }
    return up[u][0];
}