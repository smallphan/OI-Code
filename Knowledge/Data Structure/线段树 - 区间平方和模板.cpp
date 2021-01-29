#include <cstdio>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define mid  ((tree[point].l + tree[point].r) >> 1)

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int l, r, len;
    int sum, var, tag;
} tree[maxn << 2];
int n, m, q, l, r, w;

inline long long read();
void pushup(int);
void pushdn(int);
void build(int, int, int);
void modify(int, int, int, int);
int querysum(int, int, int);
int queryvar(int, int, int);

int main() {
    n = read(), m = read(), q = read();
    build(1, 1, n);
    while (m--) {
        l = read(), r = read(), w = read();
        modify(1, l, r, w);
    }
    while (q--) {
        l = read(), r = read();
        printf("[%d,%d] [sum] %d [var] %d\n", l, r, querysum(1, l, r), queryvar(1, l, r));
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void pushup(int point) {
    if (!tree[point].len) tree[point].len = tree[lson].len + tree[rson].len;
    tree[point].sum = tree[lson].sum + tree[rson].sum;
    tree[point].var = tree[lson].var + tree[rson].var;
}
void pushdn(int point) {
    if (tree[point].tag) {
        tree[lson].var += tree[lson].len * tree[point].tag * tree[point].tag + 2 * tree[point].tag * tree[lson].sum;
        tree[rson].var += tree[rson].len * tree[point].tag * tree[point].tag + 2 * tree[point].tag * tree[rson].sum;
        tree[lson].sum += tree[lson].len * tree[point].tag;
        tree[rson].sum += tree[rson].len * tree[point].tag;
        tree[lson].tag += tree[point].tag;
        tree[rson].tag += tree[point].tag;
        tree[point].tag = 0;
    }
}
void build(int point, int l, int r) {
    tree[point].l = l, tree[point].r = r;
    if (l == r) {
        tree[point].len = 1;
        tree[point].sum = tree[point].var = read();
        tree[point].var *= tree[point].var;
    } else {
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(point);
    }
}
void modify(int point, int l, int r, int key) {
    if (l <= tree[point].l && r >= tree[point].r) {
        tree[point].tag += key;
        tree[point].var += tree[point].len * key * key + 2 * key * tree[point].sum;
        tree[point].sum += tree[point].len * key;
    } else {
        pushdn(point);
        if (l <= mid) modify(lson, l, r, key);
        if (r >= mid + 1) modify(rson, l, r, key);
        pushup(point);
    }
}
int querysum(int point, int l, int r) {
    if (l <= tree[point].l && r >= tree[point].r) {
        return tree[point].sum;
    } else {
        pushdn(point);
        int ans = 0;
        if (l <= mid) ans += querysum(lson, l, r);
        if (r >= mid + 1) ans += querysum(rson, l, r);
        return ans;
    }
}
int queryvar(int point, int l, int r) {
    if (l <= tree[point].l && r >= tree[point].r) {
        return tree[point].var;
    } else {
        pushdn(point);
        int ans = 0;
        if (l <= mid) ans += queryvar(lson, l, r);
        if (r >= mid + 1) ans += queryvar(rson, l, r);
        return ans;
    }
}