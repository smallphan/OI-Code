#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define mid  ((tree[point].l + tree[point].r) >> 1)

using namespace std;

typedef long long ll;
const ll maxn = 1e5 + 5;
struct nodefir {
    ll next, end;
} edge[maxn << 1];
ll first[maxn], cnt;
struct nodesec {
    ll l, r, len;
    ll sum, tag;
} tree[maxn << 2];
struct nodethi {
    ll dfn, dep, siz;
    ll fat, son, top;
} node[maxn];
ll rak[maxn], tot, value[maxn];
ll opt, n, m, r, p, u, v, w;

inline long long read();
void addedge(ll, ll);
void dfsfir(ll, ll);
void dfssec(ll, ll);
namespace section {
    void pushup(ll);
    void pushdn(ll);
    void build(ll, ll, ll);
    void modify(ll, ll, ll, ll);
    ll query(ll, ll, ll);
}
namespace treechain {
    void modify(ll, ll, ll);
    ll query(ll, ll);
}

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), r = read(), p = read();
    for (int i = 1; i <= n; i++) value[i] = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        addedge(u, v), addedge(v, u);
    }
    dfsfir(r, r), dfssec(r, r);
    section::build(1, 1, n);
    while (m--) {
        opt = read();
        switch (opt) {
            case 1: 
                u = read(), v = read(), w = read();
                treechain::modify(u, v, w);
                break;
            case 2: 
                u = read(), v = read();
                printf("%lld\n", treechain::query(u, v) % p);
                break;
            case 3: 
                u = read(), w = read();
                section::modify(1, node[u].dfn, node[u].dfn + node[u].siz - 1, w % p);
                break;
            case 4: 
                u = read();
                printf("%lld\n", section::query(1, node[u].dfn, node[u].dfn + node[u].siz - 1) % p);
                break;
        }
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(ll start, ll end) {
    edge[++cnt] = (nodefir) { first[start], end };
    first[start] = cnt;
}
void dfsfir(ll now, ll father) {
    node[now].fat = father;
    node[now].dep = node[father].dep + 1;
    node[now].siz = 1;
    for (int i = first[now]; i != -1; i = edge[i].next) {
        ll end = edge[i].end;
        if (end == father) continue;
        dfsfir(end, now);
        node[now].siz += node[end].siz;
        if (node[end].siz > node[node[now].son].siz) node[now].son = end;
    }
}
void dfssec(ll now, ll ancestor) {
    node[now].top = ancestor;
    node[now].dfn = ++tot;
    rak[tot] = now;
    if (!node[now].son) return;
    dfssec(node[now].son, ancestor);
    for (int i = first[now]; i != -1; i = edge[i].next) {
        ll end = edge[i].end;
        if (end != node[now].son && end != node[now].fat) dfssec(end, end);
    }
}
namespace section {
    void pushup(ll point) {
        tree[point].sum = (tree[lson].sum + tree[rson].sum) % p;
    }
    void pushdn(ll point) {
        ll& tag = tree[point].tag;
        if (tag) {
            tree[lson].sum = (tree[lson].sum + tree[lson].len * tag) % p;
            tree[rson].sum = (tree[rson].sum + tree[rson].len * tag) % p;
            tree[lson].tag = (tree[lson].tag + tag) % p;
            tree[rson].tag = (tree[rson].tag + tag) % p;
            tag = 0;
        }
    }
    void build(ll point, ll l, ll r) {
        tree[point].l = l, tree[point].r = r, tree[point].len = r - l + 1;
        if (l == r) {
            tree[point].sum = value[rak[l]] % p;
        } else {
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(point);
        }
    }
    void modify(ll point, ll l, ll r, ll key) {
        if (l <= tree[point].l && r >= tree[point].r) {
            tree[point].sum = (tree[point].sum + tree[point].len * key) % p;
            tree[point].tag = (tree[point].tag + key) % p;
        } else {
            pushdn(point);
            if (l <= mid) modify(lson, l, r, key);
            if (r >= mid + 1) modify(rson, l, r, key);
            pushup(point);
        }
    }
    ll query(ll point, ll l, ll r) {
        if (l <= tree[point].l && r >= tree[point].r) {
            return tree[point].sum;
        } else {
            pushdn(point);
            ll ans = 0;
            if (l <= mid) ans = (ans + query(lson, l, r)) % p;
            if (r >= mid + 1) ans = (ans + query(rson, l, r)) % p;
            return ans;
        }
    }
}
namespace treechain {
    void modify(ll fir, ll sec, ll key) {
        while (node[fir].top != node[sec].top) {
            if (node[node[fir].top].dep < node[node[sec].top].dep) swap(fir, sec);
            section::modify(1, node[node[fir].top].dfn, node[fir].dfn, key);
            fir = node[node[fir].top].fat;
        }
        if (node[fir].dep > node[sec].dep) swap(fir, sec);
        section::modify(1, node[fir].dfn, node[sec].dfn, key);
    }
    ll query(ll fir, ll sec) {
        ll ans = 0;
        while (node[fir].top != node[sec].top) {
            if (node[node[fir].top].dep < node[node[sec].top].dep) swap(fir, sec);
            ans = (ans + section::query(1, node[node[fir].top].dfn, node[fir].dfn)) % p;
            fir = node[node[fir].top].fat;
        }
        if (node[fir].dep > node[sec].dep) swap(fir, sec);
        ans = (ans + section::query(1, node[fir].dfn, node[sec].dfn)) % p;
        return ans;
    }
}