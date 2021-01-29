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

int n, m, q, l, r, w;

struct node {
    int l, r, len;
    int sum, tag;
} tree[maxn << 2];

namespace TR {
    inline void pushup(int);
    inline void pushdn(int);
    void build(int, int, int);
    void modify(int, int, int, int);
    int query(int, int, int);
}

int main() {
    n = read(), m = read(), q = read();
    TR::build(1, 1, n);
    while (m--) {
        l = read(), r = read(), w = read();
        TR::modify(1, l, r, w);
    }
    while (q--) {
        l = read(), r = read();
        printf("[%d, %d] %d\n", l, r, TR::query(1, l, r));
    }
}

#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((tree[now].l + tree[now].r) >> 1)

namespace TR {
    inline void pushup(int now) {
        tree[now].sum = tree[lson].sum + tree[rson].sum;
    }

    inline void pushdn(int now) {
        int& tag = tree[now].tag;
        if (tag) {
            tree[lson].sum += tag * tree[lson].len;
            tree[rson].sum += tag * tree[rson].len;
            tree[lson].tag += tag;
            tree[rson].tag += tag;
            tag = 0;
        }
    }

    void build(int now, int l, int r) {
        tree[now].l = l, tree[now].r = r, tree[now].len = r - l + 1;
        if (l == r) {
            tree[now].sum = read();
        } else {
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(now);
        }
    }

    void modify(int now, int l, int r, int val) {
        if (l <= tree[now].l && r >= tree[now].r) {
            tree[now].sum += val * tree[now].len;
            tree[now].tag += val;
        } else {
            pushdn(now);
            if (l <= mid) modify(lson, l, r, val);
            if (r >= mid + 1) modify(rson, l, r, val);
            pushup(now);
        }
    }

    int query(int now, int l, int r) {
        if (l <= tree[now].l && r >= tree[now].r) {
            return tree[now].sum;
        } else {
            pushdn(now);
            int ans = 0;
            if (l <= mid) ans += query(lson, l, r);
            if (r >= mid + 1) ans += query(rson, l, r);
            return ans;
        }
    }
}