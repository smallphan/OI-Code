#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long double ld;
const int maxn = 1e3 + 5;
struct nodefir {
    ld x, y;
    friend ld operator - (nodefir fir, nodefir sec) {
        ld disx = fir.x - sec.x, disy = fir.y - sec.y;
        return sqrt(disx * disx + disy * disy);
    }
} dot[maxn];
struct nodesec {
    int sta, end;
    ld val;
    inline void put(int u, int v) {
        sta = u, end = v;
        val = dot[u] - dot[v];
    }
    inline bool operator < (const nodesec& data) const {
        return val < data.val;
    }
} edge[maxn * maxn];
int cnt, fat[maxn];
int n, m, u, v;
ld ans;

inline long long read();
namespace mode {
    inline int find(int);
    inline bool merge(int, int);
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) fat[i] = i, dot[i] = (nodefir) { read(), read() };
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[++cnt].put(i, j);
        }
    }
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        edge[++cnt].put(u, v), edge[cnt].val = 0;
    }
    sort(edge + 1, edge + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
        int sta = edge[i].sta, end = edge[i].end;
        ld val = edge[i].val;
        if (mode::merge(sta, end)) ans += val;
    }
    printf("%.2Lf\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
namespace mode {
    inline int find(int now) {
        if (now == fat[now]) return now;
        else return fat[now] = find(fat[now]);
    }
    inline bool merge(int fir, int sec) {
        fir = find(fir), sec = find(sec);
        if (fir != sec) {
            fat[fir] = sec;
            return true;
        } else return false;
    }
}