#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

namespace ips {
    inline long long read() {
        char str = getchar(); long long ans = 0, tag = 1;
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
}

using namespace ips;
using namespace std;

typedef double lf;

const int maxn = 55;
const lf skip = 1e-3;

struct node {
    int nxt, end;
    lf val;
} edge[(maxn * maxn) << 1];
int fir[maxn], cnt;

int t, n, m, u, v, tim[maxn];
lf dis[maxn], w, l, r;
bool vis[maxn];

inline void addedge(int, int, lf);
inline bool test(lf);
inline bool spfa();

int main() {
    t = read();
    for (int i = 1; i <= t; i++) {
        n = read(), m = read();
        cnt = 0, memset(fir, 0, sizeof(fir));
        l = r = 0;
        while (m--) {
            u = read(), v = read();
            scanf("%lf", &w);
            r = max(r, w);
            addedge(u, v, w);
        }
        printf("Case #%d: ", i);
        if (!test(r + 1)) puts("No cycle found.");
        else {
            while (r - l > skip) {
                lf mid = (l + r) / 2;
                if (test(mid)) r = mid;
                else l = mid;
            }
            printf("%.2lf\n", l);
        }
    }
    return 0;
}

inline void addedge(int u, int v, lf w) {
    edge[++cnt] = (node) { fir[u], v, w };
    fir[u] = cnt;
}

inline bool test(lf now) {
    for (int i = 1; i <= cnt; i++) edge[i].val -= now;
    bool tag = spfa();
    for (int i = 1; i <= cnt; i++) edge[i].val += now;
    return tag;
}

inline bool spfa() {
    memset(tim, 0, sizeof(tim));
    memset(vis, false, sizeof(vis));
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        dis[i] = 0;
        que.push(i);
    }
    vis[1] = true;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        vis[now] = false;
        for (int i = fir[now]; i; i = edge[i].nxt) {
            lf val = edge[i].val;
            int end = edge[i].end;
            if (dis[end] > dis[now] + val) {
                dis[end] = dis[now] + val;
                if (!vis[end]) {
                    que.push(end);
                    vis[end] = true;
                    if (++tim[end] > n) return true;
                }
            }
        } 
    }
    return false;
}