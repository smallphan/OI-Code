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

int n, m, q, l, r, p, w;
int tree[maxn];

namespace TR {
    inline int lowbit(int);
    inline void modify(int, int);
    inline int query(int, int);
    inline int profix(int);
}

int main() {
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) {
        w = read();
        TR::modify(i, w);
    }
    while (m--) {
        p = read(), w = read();
        TR::modify(p, w);
    }
    while (q--) {
        l = read(), r = read();
        printf("[%d, %d] %d\n", l, r, TR::query(l, r));
    }
    return 0;
}

namespace TR {
    inline int lowbit(int num) {
        return num & (-num);
    }

    inline void modify(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            tree[i] += val;
        }
    }
    
    inline int query(int l, int r) {
        return profix(r) - profix(l - 1);
    }

    inline int profix(int pos) {
        int ans = 0;
        for (int i = pos; i >= 1; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}