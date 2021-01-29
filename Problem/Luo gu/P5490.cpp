#include <map>
#include <cstdio>
#include <algorithm>

#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((tree[now].l + tree[now].r) >> 1)

using namespace std;

typedef long long li;
const int maxn = 1e6 + 5;
struct nodefir {
    li l, r, hig, val;
    bool operator < (const nodefir& data) const {
        return hig < data.hig;
    }
} line[maxn << 2];
struct nodesec {
    li l, r, len;
    li val, sum;
} tree[maxn << 2];
int n, xfir, yfir, xsec, ysec, coor[maxn << 2];
map <int, int> fin;
li ans;

inline long long read();
namespace mode {
    inline void pushup(int);
    void build(int, int, int);
    void modify(int, int, int, int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        xfir = read(), yfir = read(), xsec = read(), ysec = read();
        coor[(i << 1) - 1] = xfir, coor[i << 1] = xsec;
        line[(i << 1) - 1] = (nodefir) { xfir, xsec, yfir, 1 };
        line[i << 1] = (nodefir) { xfir, xsec, ysec, -1 };
    }
    n = n << 1;
    sort(line + 1, line + 1 + n);
    sort(coor + 1, coor + 1 + n);
    int tot = unique(coor + 1, coor + 1 + n) - (coor + 1);
    for (int i = 1; i <= tot; i++) fin[coor[i]] = i;
    mode::build(1, 1, tot - 1);
    for (int i = 1; i < n; i++) {
        mode::modify(1, fin[line[i].l], fin[line[i].r] - 1, line[i].val);
        ans += tree[1].sum * (line[i + 1].hig - line[i].hig);
    }
    printf("%lld\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
namespace mode {
    inline void pushup(int now) {
        if (tree[now].val) tree[now].sum = tree[now].len;
        else tree[now].sum = tree[lson].sum + tree[rson].sum;
    }
    void build(int now, int l, int r) {
        tree[now].l = l, tree[now].r = r, tree[now].len = coor[r + 1] - coor[l];
        if (l == r) return;
        else {
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(now);
        }
    }
    void modify(int now, int l, int r, int key) {
        if (l <= tree[now].l && r >= tree[now].r) {
            tree[now].val += key;
        } else {
            if (l <= mid) modify(lson, l, r, key);
            if (r >= mid + 1) modify(rson, l, r, key);
        }
        pushup(now);
    }
}