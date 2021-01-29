#include <algorithm>
#include <cstdio>

#define lson (point << 1)
#define rson (point << 1 | 1)

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node {
    int l, r, max, min, tag;
} tree[maxn << 2];
int n, m, q, l, r, w;

inline int read();
void pushup(int);
void pushdn(int);
void build(int, int, int);
void modify(int, int, int, int);
int query(int, int, int, bool);

int main() {
    n = read(), m = read(), q = read();
    build(1, 1, n);
    while (m--) {
        l = read(), r = read(), w = read();
        modify(1, l, r, w);
    }
    while (q--) {
        l = read(), r = read();
        printf("max[%d,%d]%d  ", l, r, query(1, l, r, true));
        printf("min[%d,%d]%d\n", l, r, query(1, l, r, false));
    }
    return 0;
}

inline int read() {
    int ans = 0, flag = 1;
    char x = getchar();
    while (x < '0' || x > '9') {
        if (x == '-') flag = -1;
        x = getchar();
    }
    while (x >= '0' && x <= '9') {
        ans = ans * 10 + x - '0';
        x = getchar();
    }
    return ans * flag;
}
void pushup(int point) {
    tree[point].max = max(tree[lson].max, tree[rson].max);
    tree[point].min = min(tree[lson].min, tree[rson].min);
}
void pushdn(int point) {
    if (tree[point].tag) {
        tree[lson].max += tree[point].tag;
        tree[rson].max += tree[point].tag;
        tree[lson].min += tree[point].tag;
        tree[rson].min += tree[point].tag;
        tree[lson].tag += tree[point].tag;
        tree[rson].tag += tree[point].tag;
        tree[point].tag = 0;
    }
}
void build(int point, int l, int r) {
    tree[point].l = l, tree[point].r = r;
    if (l == r) {
        tree[point].max = tree[point].min = read();
    } else {
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(point);
    }
}
void modify(int point, int l, int r, int key) {
    if (l <= tree[point].l && r >= tree[point].r) {
        tree[point].max += key;
        tree[point].min += key;
        tree[point].tag += key;
    } else {
        pushdn(point);
        int mid = (tree[point].l + tree[point].r) >> 1;
        if (l <= mid) modify(lson, l, r, key);
        if (r >= mid + 1) modify(rson, l, r, key);
        pushup(point);
    }
}
int query(int point, int l, int r, bool flag) {  //[flag] true=>max false=>min
    if (flag) {
        if (l <= tree[point].l && r >= tree[point].r) {
            return tree[point].max;
        } else {
            pushdn(point);
            int mid = (tree[point].l + tree[point].r) >> 1, ans = -inf;
            if (l <= mid) ans = max(ans, query(lson, l, r, flag));
            if (r >= mid + 1) ans = max(ans, query(rson, l, r, flag));
            return ans;
        }
    } else {
        if (l <= tree[point].l && r >= tree[point].r) {
            return tree[point].min;
        } else {
            pushdn(point);
            int mid = (tree[point].l + tree[point].r) >> 1, ans = inf;
            if (l <= mid) ans = min(ans, query(lson, l, r, flag));
            if (r >= mid + 1) ans = min(ans, query(rson, l, r, flag));
            return ans;
        }
    }
}