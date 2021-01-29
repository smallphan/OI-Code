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

const int maxn = 1e5 + 5;

int n, m, q, u, v;
int fat[maxn];

namespace set {
    inline void init();
    inline int find(int);
    inline void merge(int, int);
}

int main() {
    n = read(), m = read(), q = read(), set::init();
    while (m--) {
        u = read(), v = read();
        set::merge(u, v);
    }
    while (q--) {
        u = read(), v = read();
        printf("[%d <-> %d] ", u, v);
        puts(set::find(u) == set::find(v) ? "yes" : "no");
    }
    return 0;
}

namespace set {
    inline void init() {
        for (int i = 1; i <= n; i++) fat[i] = i;
    }

    inline int find(int now) {
        return now == fat[now] ? now : (fat[now] = find(fat[now]));
    }

    inline void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) fat[u] = v;
    }
}