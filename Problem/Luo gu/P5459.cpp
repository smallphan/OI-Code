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

const int maxn = 1e5 + 5;

int n, l, r, ans;
int sum[maxn], init[maxn], tree[maxn];

namespace TR {
    inline int lowbit(int);
    inline void add(int, int);
    inline int profix(int);
    inline int query(int, int);
}

signed main() {
    n = read(), l = read(), r = read();
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + read(), init[i] = sum[i];
    }
    init[n + 1] = 0;
    std::sort(init + 1, init + 1 + (n + 1));
    int size = std::unique(init + 1, init + 1 + (n + 1)) - (init + 1);
    TR::add(std::lower_bound(init + 1, init + 1 + size, 0) - init, 1);
    for (int i = 1; i <= n; i++) {
        int ql = std::lower_bound(init + 1, init + 1 + size, sum[i] - r) - (init + 1);
        int qr = std::upper_bound(init + 1, init + 1 + size, sum[i] - l) - (init + 1);
        ans += TR::query(ql, qr);
        TR::add(std::lower_bound(init + 1, init + 1 + size, sum[i]) - init, 1);
    }
    printf("%lld\n", ans);
    return 0;
}

namespace TR {
    inline int lowbit(int num) {
        return num & (-num);
    }

    inline void add(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            tree[i] += val;
        }
    }

    inline int profix(int pos) {
        int ans = 0;
        for (int i = pos; i >= 1; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }

    inline int query(int l, int r) {
        return profix(r) - profix(l);
    }
}