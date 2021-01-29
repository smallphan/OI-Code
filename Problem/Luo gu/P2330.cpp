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

const int maxn = 300 + 5;
const int maxm = 1e5 + 5;

int n, m, s, max;

struct aode {
    int u, v, w;
    inline bool operator < (const aode& tmp) const {
        return w < tmp.w;
    }
} edge[maxm];

namespace SET {
    int fat[maxn];
    inline void init();
    inline int find(int);
    inline bool merge(int, int);
}

int main() {
    n = read(), m = read(), SET::init();
    for (int i = 1; i <= m; i++) {
        edge[i] = (aode) { read(),  read(), read() };
    }
    std::sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++) {
        if (SET::merge(edge[i].u, edge[i].v)) {
            s++, max = std::max(max, edge[i].w);
        }
    }
    return printf("%d %d\n", s, max), 0;
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