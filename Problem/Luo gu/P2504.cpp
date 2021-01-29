#include <bits/stdc++.h>

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

const int maxn = 1e3 + 5;

int n, m, ans, dis[maxn];
double maxdis;

struct aode {
    int x, y;
    inline double operator - (const aode& tmp) {
        return sqrt((double) (x - tmp.x) * (x - tmp.x) + (y - tmp.y) * (y - tmp.y));
    }
} dot[maxn];

struct bode {
    int u, v;
    double w;
    inline bool operator < (const bode& tmp) const {
        return w < tmp.w;
    }
} edge[maxn * maxn];
int cnt;

namespace SET {
    int fat[maxn];
    inline void init();
    inline int find(int);
    inline bool merge(int, int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) dis[i] = read();
    m = read(), SET::init();
    for (int i = 1; i <= m; i++) {
        dot[i] = (aode) { read(), read() };
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            edge[++cnt] = (bode) { i, j, dot[i] - dot[j] };
        }
    }
    std::sort(edge + 1, edge + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
        if (SET::merge(edge[i].u, edge[i].v)) {
            maxdis = std::max(maxdis, edge[i].w);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (maxdis <= dis[i]) ans++;
    }
    return printf("%d\n", ans), 0;
}

namespace SET {
    inline void init() {
        for (int i = 1; i <= m; i++) fat[i] = i;
    }

    inline int find(int now) {
        return now == fat[now] ? now : (fat[now] = find(fat[now]));
    }

    inline bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) return fat[u] = v, true;
        else return false;
    }
}