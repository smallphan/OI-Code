#include <cstdio>

namespace ips {
    inline long long read() {
        char str = getchar(); long long ans = 0, tag = 1;
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
}

using namespace ips;
using namespace std;

const int maxn = 1e5 + 5;

struct node {
    int l, r, len;
    int sum, tag;
} tree[maxn << 2];

int n, m, opt, l, r;

namespace mode {
    inline void pushup(int);
    inline void pushdn(int);
    void build(int, int, int);
    void modify(int, int, int);
    int query(int, int, int);
}

int main() {
    n = read(), m = read();
    mode::build(1, 1, n);
    while (m--) {
        opt = read(), l = read(), r = read();
        switch (opt) {
            case 0 : mode::modify(1, l, r); break;
            case 1 : printf("%d\n", mode::query(1, l, r)); break;
        }
    }
    return 0;
}

#define l(now) tree[now].l
#define r(now) tree[now].r
#define len(now) tree[now].len
#define sum(now) tree[now].sum
#define tag(now) tree[now].tag
#define lson (now << 1)
#define rson (now << 1 | 1)

namespace mode {
    inline void pushup(int now) {
        sum(now) = sum(lson) + sum(rson);
    }

    inline void pushdn(int now) {
        if (tag(now)) {
            sum(lson) = len(lson) - sum(lson);
            sum(rson) = len(rson) - sum(rson);
            tag(lson) ^= 1;
            tag(rson) ^= 1;
            tag(now) = 0;
        }
    }

    void build(int now, int l, int r) {
        l(now) = l, r(now) = r, len(now) = r - l + 1;
        if (l == r) return;
        else {
            int mid = (l + r) >> 1;
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(now);
        }
    }

    void modify(int now, int l, int r) {
        if (l <= l(now) && r >= r(now)) {
            sum(now) = len(now) - sum(now);
            tag(now) ^= 1;
        } else {
            pushdn(now);
            int mid = (l(now) + r(now)) >> 1;
            if (l <= mid) modify(lson, l, r);
            if (r >= mid + 1) modify(rson, l, r);
            pushup(now);
        }
    }

    int query(int now, int l, int r) {
        if (l <= l(now) && r >= r(now)) {
            return sum(now);
        } else {
            pushdn(now);
            int mid = (l(now) + r(now)) >> 1, ans = 0;
            if (l <= mid) ans += query(lson, l, r);
            if (r >= mid + 1) ans += query(rson, l, r);
            return ans;
        }
    }
}