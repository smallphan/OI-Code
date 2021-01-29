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

const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int v, w;
}; std::vector<node> edge[maxn];

int dis[maxn], cnt[maxn];
bool vis[maxn];
std::queue<int> que;

int t, n, m, u, v, w;

inline void init();
inline void work();
inline bool spfa();

int main() {
    t = read();
    while (t--) work();
    return 0;
}

inline void init() {
    for (int i = 1; i <= n; i++) edge[i].clear();
    memset(cnt, 0, sizeof(cnt));
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    while (!que.empty()) que.pop();
    dis[1] = 0, vis[1] = true, que.push(1);
}

inline void work() {
    init();
    n = read(), m = read();
    while (m--) {
        u = read(), v = read(), w = read();
        edge[u].pb((node) { v, w });
        if (w >= 0) edge[v].pb((node) { u, w });
    }
    printf("%s\n", spfa() ? "YES" : "NO");
}

inline bool spfa() {
    while (!que.empty()) {
        int u = que.front();
        vis[u] = false, que.pop();
        for (int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i].v, w = edge[u][i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
                if (!vis[v]) {
                    vis[v] = true, que.push(v);
                }
            }
        }
    }
    return false;
}