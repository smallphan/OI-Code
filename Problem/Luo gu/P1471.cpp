#include <cstdio>

#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((tree[now].l + tree[now].r) >> 1)

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int l, r, len;
    double sum, var, tag;
} tree[maxn << 2];
int n, m, opt, l, r;

inline long long read();
namespace mode {
    inline void pushup(int);
    inline void pushdn(int);
    void build(int, int, int);
    void modify(int, int, int, double);
    double querysum(int, int, int);
    double queryvar(int, int, int);
}

int main() {
    n = read(), m = read();
    mode::build(1, 1, n);
    while (m--) {
        opt = read(), l = read(), r = read();
        double len = r - l + 1;
        switch (opt) {
            case 1 : {
                double w;
                scanf("%lf", &w);
                mode::modify(1, l, r, w);
                break;
            } case 2 : {
                double sum = mode::querysum(1, l, r);
                printf("%.4lf\n", (sum / len));
                break;
            } case 3 : {
                double sum = mode::querysum(1, l, r);
                double var = mode::queryvar(1, l, r);
                printf("%.4lf\n", ((var / len) - (sum / len) * (sum / len)));
                break;
            }
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
namespace mode {
    inline void pushup(int now) {
        tree[now].sum = tree[lson].sum + tree[rson].sum;
        tree[now].var = tree[lson].var + tree[rson].var;
    }
    inline void pushdn(int now) {
        double& tag = tree[now].tag;
        if (tag) {
            tree[lson].var += 2 * tag * tree[lson].sum + tree[lson].len * tag * tag;
            tree[rson].var += 2 * tag * tree[rson].sum + tree[rson].len * tag * tag;
            tree[lson].sum += tree[lson].len * tag;
            tree[rson].sum += tree[rson].len * tag;
            tree[lson].tag += tag;
            tree[rson].tag += tag;
            tag = 0;
        }
    }
    void build(int now, int l, int r) {
        tree[now].l = l, tree[now].r = r, tree[now].len = r - l + 1;
        if (l == r) {
            scanf("%lf", &tree[now].sum);
            tree[now].var = tree[now].sum * tree[now].sum;
        } else {
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(now);
        }
    }
    void modify(int now, int l, int r, double key) {
        if (l <= tree[now].l && r >= tree[now].r) {
            tree[now].tag += key;
            tree[now].var += 2 * key * tree[now].sum + tree[now].len * key * key;
            tree[now].sum += tree[now].len * key;
        } else {
            pushdn(now);
            if (l <= mid) modify(lson, l, r, key);
            if (r >= mid + 1) modify(rson, l, r, key);
            pushup(now);
        }
    }
    double querysum(int now, int l, int r) {
        if (l <= tree[now].l && r >= tree[now].r) {
            return tree[now].sum;
        } else {
            pushdn(now);
            double ans = 0;
            if (l <= mid) ans += querysum(lson, l, r);
            if (r >= mid + 1) ans += querysum(rson, l, r);
            return ans;
        }
    }
    double queryvar(int now, int l, int r) {
        if (l <= tree[now].l && r >= tree[now].r) {
            return tree[now].var;
        } else {
            pushdn(now);
            double ans = 0;
            if (l <= mid) ans += queryvar(lson, l, r);
            if (r >= mid + 1) ans += queryvar(rson, l, r);
            return ans;
        }
    }
}