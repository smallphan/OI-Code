#include <cstdio>
#include <algorithm>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define mid  ((tree[point].l + tree[point].r) >> 1)

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node {
    int l, r, num;
} tree[maxn << 2];
int n, q, l, r;

inline long long read();
void pushup(int);
void pushdn(int);
void build(int, int, int);
int query(int, int, int);

int main() {
    n = read(), q = read();
    build(1, 1, n);
    while (q--) {
        l = read(), r = read();
        printf("[%d,%d] [min] %d\n", l, r, query(1, l, r));
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
    tree[point].num = min(tree[lson].num, tree[rson].num);
}
void build(int point, int l, int r) {
    tree[point].l = l, tree[point].r = r;
    if (l == r) {
        tree[point].num = read();
    } else {
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(point);
    }
}
int query(int point, int l, int r) {
    if (l <= tree[point].l && r >= tree[point].r) {
        return tree[point].num;
    } else {
        int ans = inf;
        if (l <= mid) ans = min(ans, query(lson, l, r));
        if (r >= mid + 1) ans = min(ans, query(rson, l, r));
        return ans;
    }
}