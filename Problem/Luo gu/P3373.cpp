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

int n, m, p, l, r, w, opt;

struct node {
    int l, r, len;
    int sum, add, mul;
} tree[maxn << 2];

namespace TR {
    inline void pushup(int);
    inline void pushdn(int);
    void build(int, int, int);
    void updadd(int, int, int, int);
    void updmul(int, int, int, int);
    int query(int, int, int);
}

signed main() {
    n = read(), m = read(), p = read();
    TR::build(1, 1, n);
    while (m--) {
        opt = read();
        if (opt == 1) {
            l = read(), r = read(), w = read();
            TR::updmul(1, l, r, w);
        } else if (opt == 2) {
            l = read(), r = read(), w = read();
            TR::updadd(1, l, r, w);
        } else if (opt == 3) {
            l = read(), r = read();
            printf("%lld\n", TR::query(1, l, r));
        }
    }
    return 0;
}

#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((tree[now].l + tree[now].r) >> 1)

namespace TR {
    inline void pushup(int now) {
        tree[now].sum = (tree[lson].sum + tree[rson].sum) % p;
    }

    inline void pushdn(int now) {
        tree[lson].sum = (tree[lson].sum * tree[now].mul + tree[lson].len * tree[now].add) % p;
        tree[rson].sum = (tree[rson].sum * tree[now].mul + tree[rson].len * tree[now].add) % p;
        tree[lson].mul = (tree[lson].mul * tree[now].mul) % p;
        tree[rson].mul = (tree[rson].mul * tree[now].mul) % p;
        tree[lson].add = (tree[lson].add * tree[now].mul + tree[now].add) % p;
        tree[rson].add = (tree[rson].add * tree[now].mul + tree[now].add) % p;
        tree[now].mul = 1, tree[now].add = 0;
    }

    void build(int now, int l, int r) {
        tree[now].l = l, tree[now].r = r, tree[now].len = r - l + 1, tree[now].mul = 1;
        if (l == r) {
            tree[now].sum = read();
        } else {
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(now);
        }
    }

    void updadd(int now, int l, int r, int val) {
        if (l <= tree[now].l && r >= tree[now].r) {
            tree[now].sum = (tree[now].sum + tree[now].len * val) % p;
            tree[now].add = (tree[now].add + val) % p;
        } else {
            pushdn(now);
            if (l <= mid) updadd(lson, l, r, val);
            if (r >= mid + 1) updadd(rson, l, r, val);
            pushup(now);
        }
    }

    void updmul(int now, int l, int r, int val) {
        if (l <= tree[now].l && r >= tree[now].r) {
            tree[now].sum = (tree[now].sum * val) % p;
            tree[now].add = (tree[now].add * val) % p;
            tree[now].mul = (tree[now].mul * val) % p;
        } else {
            pushdn(now);
            if (l <= mid) updmul(lson, l, r, val);
            if (r >= mid + 1) updmul(rson, l, r, val);
            pushup(now);
        }
    }

    int query(int now, int l, int r) {
        if (l <= tree[now].l && r >= tree[now].r) {
            return tree[now].sum;
        } else {
            pushdn(now);
            int ans = 0;
            if (l <= mid) ans = (ans + query(lson, l, r)) % p;
            if (r >= mid + 1) ans = (ans + query(rson, l, r)) % p;
            return ans;
        }
    }
}