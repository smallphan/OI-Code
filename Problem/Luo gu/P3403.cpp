#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

#define int long long

using namespace std;

const int inf = 0x7f7f7f7f;
const int maxn = 2e5 + 5;
struct nodefir {
    int end, value;
}; vector <nodefir> edge[maxn];
struct nodesec {
    int point, dis;
    bool operator < (const nodesec& data) const {
        return dis > data.dis;
    }
}; priority_queue <nodesec> heap;
int h, x, y, z, ans;
int dis[maxn];
bool vis[maxn];

inline long long read();
inline void dijkstra(int);

signed main() {
    h = read(), x = read(), y = read(), z = read();
    if (x == 1 || y == 1 || z == 1) {
        printf("%lld\n", h);
    } else {
        for (int i = 0; i < x; i++) {
            edge[i].push_back((nodefir) { (i + y) % x, y });
            edge[i].push_back((nodefir) { (i + z) % x, z });
        }
        dijkstra(1);
        for (int i = 0; i < x; i++) {
            if (dis[i] <= h) ans += (h - dis[i]) / x + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void dijkstra(int start) {
    memset(dis, inf, sizeof(dis));
    dis[start] = 1;
    heap.push((nodesec) { start, 1 });
    while (!heap.empty()) {
        int now = heap.top().point;
        heap.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i].end, value = edge[now][i].value;
            if (!vis[end] && dis[end] > dis[now] + value) {
                dis[end] = dis[now] + value;
                heap.push((nodesec) { end, dis[end] });
            }
        }
    }
}