#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;
struct nodef {
    int x, y;
    inline double operator - (const nodef& data) const {
        double disx = x - data.x, disy = y - data.y;
        return sqrt(disx * disx + disy * disy);
    }
} dot[maxn];
struct nodes {
    int beg, end;
    double val;
    inline void put(int u, int v) {
        beg = u, end = v;
        val = dot[u] - dot[v];
    }
    inline bool operator < (const nodes& data) const {
        return val < data.val;
    }
} edge[maxn * maxn];
int n, k, cnt, fat[maxn];
vector <int> use;

inline long long read();
namespace mode {
    inline int find(int);
    inline bool merge(int, int);
}

int main() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) fat[i] = i, dot[i] = (nodef) { read(), read() };
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[++cnt].put(i, j);
        }
    }
    sort(edge + 1, edge + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
        int beg = edge[i].beg, end = edge[i].end;
        double val = edge[i].val;
        if (mode::merge(beg, end)) use.push_back(i);
    }
    int tot = use.size();
    printf("%.2lf\n", edge[use[tot + 1 - k]].val);
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