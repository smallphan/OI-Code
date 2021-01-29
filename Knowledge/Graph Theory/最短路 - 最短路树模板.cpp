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
const int maxm = maxn << 2;

int n, m, s, u, v, w;

struct aode {
    int nxt, end, val;
} edge[maxm];
int fir[maxn], cnt;

struct bode {
    int dot, dis;
    inline bool operator < (const bode& tmp) const {
        return dis > tmp.dis;
    }
}; std::priority_queue<bode> heap;
bool vis[maxn], add[maxm];
int dis[maxn], pre[maxn];

std::vector<int> son[maxn];

inline void addedge(int, int, int);
inline void dijkstra(int);
void dfs(int, int);

int main() {
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    dijkstra(s), dfs(s, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < son[i].size(); j++) {
            printf("[%d->%d] ", i, son[i][j]);
        }
    }
    return 0;
}

inline void addedge(int u, int v, int w) {
    edge[++cnt] = (aode) { fir[u], v, w }, fir[u] = cnt;
    edge[++cnt] = (aode) { fir[v], u, w }, fir[v] = cnt;
}

inline void dijkstra(int s) {
    std::memset(dis, 0x3f, sizeof(dis));
    dis[s] = true;
    heap.push((bode) { s, dis[s] });
    while (!heap.empty()) {
        int now = heap.top().dot;
        heap.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = fir[now]; i; i = edge[i].nxt) {
            int end = edge[i].end, val = edge[i].val;
            if (dis[end] > dis[now] + val) {
                dis[end] = dis[now] + val;
                pre[end] = i;
                if (!vis[end]) heap.push((bode) { end, dis[end] });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        add[pre[i]] = true;
    }
}

void dfs(int now, int fat) {
    for (int i = fir[now]; i; i = edge[i].nxt) {
        int end = edge[i].end;
        if (end == fat || !add[i]) continue;
        son[now].pb(end);
        dfs(end, now);
    }
}