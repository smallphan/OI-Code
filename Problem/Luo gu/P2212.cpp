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

const int maxn = 2e3 + 5;

int n, lim, ans;

struct aode {
    int x, y;
    inline int operator - (const aode& tmp) {
        return (x - tmp.x) * (x - tmp.x) + (y - tmp.y) * (y - tmp.y);
    }
} dot[maxn];

struct bode {
    int u, v, w;
    inline bool operator < (const bode& tmp) const {
        return w < tmp.w;
    }
} edge[maxn * maxn];
int cnt;

inline bool check();

namespace SET {
    int fat[maxn];
    inline void init();
    inline int find(int);
    inline bool merge(int, int);
}

int main() {
    n = read(), lim = read(), SET::init();
    for (int i = 1; i <= n; i++) {
        dot[i] = (aode) { read(), read() };
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[++cnt] = (bode) { i, j, dot[i] - dot[j] };
        }
    }
    std::sort(edge + 1, edge + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
        if (edge[i].w < lim) continue;
        if (SET::merge(edge[i].u, edge[i].v)) {
            ans += edge[i].w;
        }
    }
    if (check()) return printf("%d\n", ans), 0;
    else return puts("-1"), 0;
}

inline bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (SET::find(i) != SET::find(j)) return false;
        }
    }
    return true;
}

namespace SET {
    inline void init() {
        for (int i = 1; i <= n; i++) fat[i] = i;
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