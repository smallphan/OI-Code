#include <bits/stdc++.h>

#define pb push_back

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

typedef unsigned long long uli;

const int maxn = 1e6 + 5;
const int lim = 70;

uli n, m, c, k, u, v, ans = 1, sum;
std::vector<uli> work[lim];
std::map<uli, bool> vis;

inline void deal(uli);

int main() {
    n = read(), m = read(), c = read(), k = read();
    for (int i = 1; i <= n; i++) sum |= read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        work[u].pb(v);
    }
    deal(sum);
    for (int i = 0; i < k; i++) {
        bool tag = true;
        for (int j = 0; j < work[i].size(); j++) {
            if (!vis[work[i][j]]) {
                tag = false;
                break;
            }
        }
        if (tag) ans = ans << 1;
    }
    if (ans == 0 && n == 0) puts("18446744073709551616"); // ull 2^64 -> 0
    else printf("%llu\n", ans - n);
    return 0;
}

inline void deal(uli num) {
    uli bit = 0;
    while (num) {
        if (num & 1) {
            for (int i = 0; i < work[bit].size(); i++) {
                vis[work[bit][i]] = true;
            }
        }
        num = num >> 1;
        bit++;
    }
}