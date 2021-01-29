#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 5, maxm = 5e4 + 5, inf = 0x7f7f7f7f;
struct nodef {
    int beg, end, val;
    inline bool operator < (const nodef& data) const {
        return val > data.val;
    }
} edgef[maxm];
struct nodes {
    int nex, end, val;
} edges[maxm << 1];
int fir[maxn], cnt;
int n, m, q, u, v;
bool vis[maxn];

inline long long read();
inline void addedge(int, int, int);
void dfs(int);
namespace modef {
    int fat[maxn];
    inline void init();
    inline int find(int);
    inline bool merge(int, int);
}
namespace modes {
    int up[maxn][25], minv[maxn][25], dep[maxn], lg[maxn];
    inline void init();
    inline int lca(int, int);
}

int main() {
    n = read(), m = read(), modef::init();
    for (int i = 1; i <= m; i++) edgef[i] = (nodef) { read(), read(), read() };
    sort(edgef + 1, edgef + 1 + m);
    for (int i = 1; i <= m; i++) {
        int u = edgef[i].beg, v = edgef[i].end, w = edgef[i].val;
        if (modef::merge(u, v)) addedge(u, v, w), addedge(v, u, w);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            modes::dep[i] = 1;
            dfs(i);
            modes::up[i][0] = i;
            modes::minv[i][0] = inf;
        }
    }
    modes::init();
    q = read();
    while (q--) {
        u = read(), v = read();
        printf("%d\n", modes::lca(u, v));
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void addedge(int beg, int end, int val) {
    edges[++cnt] = (nodes) { fir[beg], end, val };
    fir[beg] = cnt;
}
void dfs(int now) {
    vis[now] = true;
    for (int i = fir[now]; i; i = edges[i].nex) {
        int end = edges[i].end, val = edges[i].val;
        if (vis[end]) continue;
        modes::dep[end] = modes::dep[now] + 1;
        modes::up[end][0] = now;
        modes::minv[end][0] = val;
        dfs(end);
    }
}
namespace modef {
    inline void init() {
        for (int i = 1; i <= n; i++) fat[i] = i;
    }
    inline int find(int now) {
        return now == fat[now] ? now : fat[now] = find(fat[now]);
    }
    inline bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            fat[u] = v;
            return true;
        } else return false;
    }
}
namespace modes {
    inline void init() {
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
        for (int s = 1; s <= lg[n]; s++) {
            for (int i = 1; i <= n; i++) {
                up[i][s] = up[up[i][s - 1]][s - 1];
                minv[i][s] = min(minv[i][s - 1], minv[up[i][s - 1]][s - 1]);
            }
        }
    }
    inline int lca(int u, int v) {
        if (modef::find(u) != modef::find(v)) return -1;
        int ans = inf;
        if (dep[u] < dep[v]) swap(u, v);
        while (dep[u] > dep[v]) {
            ans = min(ans, minv[u][lg[dep[u] - dep[v]]]);
            u = up[u][lg[dep[u] - dep[v]]];
        }
        if (u == v) return ans;
        for (int s = lg[dep[u]]; s >= 0; s--) {
            if (up[u][s] != up[v][s]) {
                ans = min(ans, min(minv[u][s], minv[v][s]));
                u = up[u][s], v = up[v][s];
            }
        }
        ans = min(ans, min(minv[u][0], minv[v][0]));
        return ans;
    }
}