#include <cstdio>
#include <vector>
#include <cstring>

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

const int maxn = 3e3 + 5;
const int inf = 1e6;

struct node {
    int end;
    lf val;
}; vector<node> edge[maxn];

int n, m, u, v;
bool vis[maxn], judge;
lf dis[maxn], w, l = -inf, r = inf;

inline void check(int, lf);

int main() {
    n = read(), m = read();
    while (m--) {
        u = read(), v = read();
        scanf("%lf", &w);
        edge[u].push_back((node) { v, w });
    }
    while (r - l > 1e-10) {
        lf mid = (l + r) / 2;
        judge = false;
        memset(dis, 0, sizeof(dis));
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            check(i, mid);
            if (judge) break;
        }
        if (judge) r = mid;
        else l = mid;
    }
    printf("%.8lf\n", l);
    return 0;
}

inline void check(int now, lf w) {
    vis[now] = true;
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i].end;
        lf val = edge[now][i].val;
        if (dis[end] > dis[now] + val - w) {
            if (vis[end] || judge) {
                judge = true;
                break;
            }
            dis[end] = dis[now] + val - w;
            check(end, w);
        }
    }
    vis[now] = false;
}