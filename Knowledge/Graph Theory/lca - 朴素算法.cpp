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

int fat[maxn];
int n, s, q, u, v;
std::vector<int> edge[maxn], tmpu, tmpv;

void dfs(int, int);
inline int lca(int, int);

int main() {
    n = read(), s = read(), q = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        edge[u].pb(v), edge[v].pb(u);
    }
    dfs(s, s);
    while (q--) {
        u = read(), v = read();
        printf("lca [%d, %d] == %d\n", u, v, lca(u, v));
    }
}

void dfs(int now, int dad) {
    fat[now] = dad;
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i];
        if (end != dad) dfs(end, now);
    }
}

inline int lca(int u, int v) {
    tmpu.clear(), tmpv.clear();
    while (u != s) tmpu.pb(u), u = fat[u];
    while (v != s) tmpv.pb(v), v = fat[v];
    tmpu.pb(s), tmpv.pb(s);
    std::reverse(tmpu.begin(), tmpu.end());
    std::reverse(tmpv.begin(), tmpv.end());
    int ans = 0;
    for (int i = 0; i < std::min(tmpu.size(), tmpv.size()); i++) {
        if (tmpu[i] == tmpv[i]) ans = tmpu[i];
        else break;
    }
    return ans;
}