#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

#define int long long

using namespace std;

const int maxn = 1e5 + 5, inf = 0x7f7f7f7f;
struct nodef {
    int end, val;
}; vector<nodef> edge[maxn];
struct nodes {
    int dot, dis;
    inline bool operator < (const nodes& data) const {
        return data.dis < dis;
    }
}; priority_queue<nodes> heap;
int n, m, s, u, v, w, dis[maxn];
bool vis[maxn];

inline long long read();
inline void dijkstra(int);

signed main() {
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[u].push_back((nodef) { v, w });
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) printf("%lld ", dis[i]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void dijkstra(int beg) {
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[beg] = 0;
    heap.push((nodes) { beg, 0 });
    while (!heap.empty()) {
        int now = heap.top().dot;
        heap.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i].end, val = edge[now][i].val;
            if (dis[end] > dis[now] + val) {
                dis[end] = dis[now] + val;
                if (!vis[end]) heap.push((nodes) { end, dis[end] });
            }
        }
    }
}