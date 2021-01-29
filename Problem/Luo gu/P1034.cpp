#include <bits/stdc++.h>

#define int long long

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

const int maxn = 55;
const int inf = 505;
const int maxinf = 1ll << 62;

int n, k, ans = maxinf;

struct nodea {
    int x, y;
} dot[maxn];

struct nodeb {
    int l, r, u, d;
    nodeb() {
        l = d = inf, r = u = -inf;
    }

    inline int s() {
        return (r - l) * (u - d);
    }
};

struct nodec {
    nodeb cub[5];
    inline int sum() {
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += cub[i].s();
        }
        return ans;
    }
} data;

void dfs(int, nodec);
inline void chkmin(int&, int);
inline void chkmax(int&, int);
inline bool check(nodec&, int);

signed main() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        dot[i] = (nodea) { read(), read() };
    }
    dfs(1, data);
    return printf("%lld\n", ans), 0;
}

void dfs(int now, nodec data) {
    if (now == n + 1) {
        chkmin(ans, data.sum());
    } else {
        for (int i = 1; i <= k; i++) {
            nodec tmp = data;
            chkmin(tmp.cub[i].l, dot[now].x);
            chkmax(tmp.cub[i].r, dot[now].x);
            chkmin(tmp.cub[i].d, dot[now].y);
            chkmax(tmp.cub[i].u, dot[now].y);
            if (check(tmp, i)) dfs(now + 1, tmp);
        }
    }
}

inline void chkmin(int& a, int b) {
    a = a < b ? a : b;
}

inline void chkmax(int& a, int b) {
    a = a > b ? a : b;
}

inline bool check(nodec& tmp, int now) {
    bool tag = false;
    for (int i = 1; i <= k; i++) {
        if (i == now) continue;
        tag |= !(tmp.cub[now].l > tmp.cub[i].r || tmp.cub[now].r < tmp.cub[i].l
        || tmp.cub[now].d > tmp.cub[i].u || tmp.cub[now].u < tmp.cub[i].d);
    }
    return !tag;
}