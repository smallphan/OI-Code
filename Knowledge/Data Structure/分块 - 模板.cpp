#include <cmath>
#include <cstdio>
#include <algorithm>

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

using namespace std;

const int maxt = 1e3 + 5;
const int maxn = maxt * maxt;

struct node {
    int l, r;
    int sum, tag;
} block[maxt];
int len, tot, bel[maxn];

int n, m, q, l, r, w;
int num[maxn];

inline void build();
inline void modify(int, int, int);
inline int query(int, int);

int main() {
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    build();
    while (m--) {
        l = read(), r = read(), w = read();
        modify(l, r, w);
    }
    while (q--) {
        l = read(), r = read();
        printf("[%d,%d] %d\n", l, r, query(l, r));
    }
    return 0;
}

inline void build() {
    len = sqrt(n);
    tot = n / len + (n % len != 0);
    for (int i = 1; i <= tot; i++) {
        block[i].l = (i - 1) * len + 1;
        block[i].r = i * len;
    }
    block[tot].r = n;
    for (int i = 1; i <= n; i++) {
        bel[i] = (i - 1) / len + 1;
        block[bel[i]].sum += num[i];
    }
}

inline void modify(int l, int r, int val) {
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; i++) {
            num[i] += val;
            block[bel[i]].sum += val;
        }
    } else {
        int s = bel[l] + (block[bel[l]].l != l);
        int e = bel[r] - (block[bel[r]].r != r);
        for (int i = s; i <= e; i++) block[i].tag += val;
        if (block[bel[l]].l != l) {
            for (int i = l; i <= block[bel[l]].r; i++) {
                num[i] += val;
                block[bel[i]].sum += val;
            }
        }
        if (block[bel[r]].r != r) {
            for (int i = block[bel[r]].l; i <= r; i++) {
                num[i] += val;
                block[bel[i]].sum += val;
            }
        }
    }
}

inline int query(int l, int r) {
    if (l > r) swap(l, r);
    int ans = 0;
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; i++) {
            ans += num[i] + block[bel[i]].tag;
        }
    } else {
        int s = bel[l] + (block[bel[l]].l != l);
        int e = bel[r] - (block[bel[r]].r != r);
        for (int i = s; i <= e; i++) {
            ans += block[i].sum + block[i].tag * (block[i].r - block[i].l + 1);
        }
        if (block[bel[l]].l != l) {
            for (int i = l; i <= block[bel[l]].r; i++) {
                ans += num[i] + block[bel[i]].tag;
            }
        }
        if (block[bel[r]].r != r) {
            for (int i = block[bel[r]].l; i <= r; i++) {
                ans += num[i] + block[bel[i]].tag;
            }
        }       
    }
    return ans;
}