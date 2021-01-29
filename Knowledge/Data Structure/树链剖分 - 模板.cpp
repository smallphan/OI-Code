#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define mid  ((tree[point].l + tree[point].r) >> 1)

using namespace std;

const int maxn = 1e5 + 5;
struct nodefir {
    int next, end;
} edge[maxn << 1];
int first[maxn], cnt;
struct nodesec {
    int l, r, len;
    int sum, tag;
} tree[maxn << 2];
struct nodethi {
    int dfn, dep, siz;
    int fat, son, top;
} node[maxn];
int rak[maxn], tot, value[maxn];
int n, m, q, s, u, v, w;

inline long long read();
void addedge(int, int);
void dfsfir(int, int);
void dfssec(int, int);
namespace section {
    void pushup(int);
    void pushdn(int);
    void build(int, int, int);
    void modify(int, int, int, int);
    int query(int, int, int);
}
namespace treechain {
    void modify(int, int, int);
    int query(int, int);
}

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), q = read(), s = read();
    for (int i = 1; i <= n; i++) value[i] = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        addedge(u, v), addedge(v, u);
    }
    dfsfir(s, s), dfssec(s, s);
    section::build(1, 1, n);
    while (m--) {
        u = read(), v = read(), w = read();
        treechain::modify(u, v, w);
    }
    while (q--) {
        u = read(), v = read();
        printf("[%d->%d] [value] %d\n", u, v, treechain::query(u, v));
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end) {
    edge[++cnt] = (nodefir) { first[start], end };
    first[start] = cnt;
}
void dfsfir(int now, int father) {
    node[now].fat = father;
    node[now].dep = node[father].dep + 1;
    node[now].siz = 1;
    for (int i = first[now]; i != -1; i = edge[i].next) {
        int end = edge[i].end;
        if (end != father) {
            dfsfir(end, now);
            node[now].siz += node[end].siz;
            if (node[end].siz > node[node[now].son].siz) node[now].son = end;
        }
    }
}
void dfssec(int now, int ancestor) {
    node[now].top = ancestor;
    node[now].dfn = ++tot;
    rak[tot] = now;
    if (!node[now].son) return;
    dfssec(node[now].son, ancestor);
    for (int i = first[now]; i != -1; i = edge[i].next) {
        int end = edge[i].end;
        if (end != node[now].son && end != node[now].fat) dfssec(end, end);
    }
}
namespace section {
    void pushup(int point) {
        tree[point].sum = tree[lson].sum + tree[rson].sum;
    }
    void pushdn(int point) {
        int& tag = tree[point].tag;
        if (tag) {
            tree[lson].sum += tree[lson].len * tag;
            tree[rson].sum += tree[rson].len * tag;
            tree[lson].tag += tag;
            tree[rson].tag += tag;
            tag = 0;
        }
    }
    void build(int point, int l, int r) {
        tree[point].l = l, tree[point].r = r, tree[point].len = r - l + 1;
        if (l == r) {
            tree[point].sum = value[rak[l]];
        } else {
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(point);
        }
    }
    void modify(int point, int l, int r, int key) {
        if (l <= tree[point].l && r >= tree[point].r) {
            tree[point].sum += tree[point].len * key;
            tree[point].tag += key;
        } else {
            pushdn(point);
            if (l <= mid) modify(lson, l, r, key);
            if (r >= mid + 1) modify(rson, l, r, key);
            pushup(point);
        }
    }
    int query(int point, int l, int r) {
        if (l <= tree[point].l && r >= tree[point].r) {
            return tree[point].sum;
        } else {
            pushdn(point);
            int ans = 0;
            if (l <= mid) ans += query(lson, l, r);
            if (r >= mid + 1) ans += query(rson, l, r);
            return ans;
        }
    }
}
namespace treechain {
    void modify(int fir, int sec, int key) {
        while (node[fir].top != node[sec].top) {
            if (node[node[fir].top].dep < node[node[sec].top].dep) swap(fir, sec);
            section::modify(1, node[node[fir].top].dfn, node[fir].dfn, key);
            fir = node[node[fir].top].fat;
        }
        if (node[fir].dep > node[sec].dep) swap(fir, sec);
        section::modify(1, node[fir].dfn, node[sec].dfn, key);
    }
    int query(int fir, int sec) {
        int ans = 0;
        while (node[fir].top != node[sec].top) {
            if (node[node[fir].top].dep < node[node[sec].top].dep) swap(fir, sec);
            ans += section::query(1, node[node[fir].top].dfn, node[fir].dfn);
            fir = node[node[fir].top].fat;
        }
        if (node[fir].dep > node[sec].dep) swap(fir, sec);
        ans += section::query(1, node[fir].dfn, node[sec].dfn);
        return ans;
    }
}