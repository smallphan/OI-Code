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

const int lim = 25;
const int maxn = 1e5 + 5;

int n, m, l, r;
int st[maxn][lim], lg[maxn];

inline void init();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        st[i][0] = read();
    }
    init();
    while (m--) {
        l = read(), r = read();
        printf("%d\n", std::max(st[l][lg[r - l + 1]], st[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]));
    }
    return 0;
}

inline void init() {
    for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int s = 1; s <= lg[n]; s++) {
        for (int i = 1; i + (1 << s) - 1 <= n; i++) {
            st[i][s] = std::max(st[i][s - 1], st[i + (1 << (s - 1))][s - 1]);
        }
    }
}