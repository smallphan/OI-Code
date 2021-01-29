#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define mid ((tree[point].l + tree[point].r) >> 1)

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node {
    int l, r, len, tag;
    int num[4];
    /* 
     * num[i] :
     * i = 0 ==> sum | the sum of section
     * i = 1 ==> var | the sum of section's square
     * i = 2 ==> max | the max number of the section
     * i = 3 ==> min | the min number of the section
     */
} tree[maxn << 2];
int opt, n, m, q, l, r, w;

inline long long read();
int init(int);
int deal(int&, int, int);
string getstring(int);
void pushup(int);
void pushdn(int);
void build(int, int, int);
void modify(int, int, int, int);
int query(int, int, int, int);
void principle();

int main() {
    n = read(), m = read(), q = read();
    build(1, 1, n);
    while (m--) {
        l = read(), r = read(), w = read();
        modify(1, l, r, w);
    }
    principle();
    while (q--) {
        opt = read(), l = read(), r = read();
        cout << "[" << getstring(opt) << "] ";
        printf("[%d,%d] %d\n", l, r, query(1, l, r, opt));
    }
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = ans * 10 + str - '0'; str = getchar(); }
    return ans * flag;
}
int init(int flag) {
    switch (flag) {
        case 0: return 0;
        case 1: return 0;
        case 2: return -inf;
        case 3: return inf;
    }
}
int deal(int& ans, int query, int flag) {
    switch (flag) {
        case 0: ans += query; break;
        case 1: ans += query; break;
        case 2: ans = max(ans, query); break;
        case 3: ans = min(ans, query); break;
    }
}
string getstring(int flag) {
    switch (flag) {
        case 0 : return "sum";
        case 1 : return "var";
        case 2 : return "max";
        case 3 : return "min";
    }
}
void pushup(int point) {
    if (!tree[point].len) tree[point].len = tree[lson].len + tree[rson].len;
    tree[point].num[0] = tree[lson].num[0] + tree[rson].num[0];
    tree[point].num[1] = tree[lson].num[1] + tree[rson].num[1];
    tree[point].num[2] = max(tree[lson].num[2], tree[rson].num[2]);
    tree[point].num[3] = min(tree[lson].num[3], tree[rson].num[3]);
}
void pushdn(int point) {
    if (tree[point].tag) {
        tree[lson].num[1] += tree[lson].len * tree[point].tag * tree[point].tag
            + 2 * tree[point].tag * tree[lson].num[0];
        tree[rson].num[1] += tree[rson].len * tree[point].tag * tree[point].tag
            + 2 * tree[point].tag * tree[rson].num[0];
        tree[lson].num[0] += tree[lson].len * tree[point].tag;
        tree[rson].num[0] += tree[rson].len * tree[point].tag;
        tree[lson].num[2] += tree[point].tag;
        tree[rson].num[2] += tree[point].tag;
        tree[lson].num[3] += tree[point].tag;
        tree[rson].num[3] += tree[point].tag;
        tree[lson].tag += tree[point].tag;
        tree[rson].tag += tree[point].tag;
        tree[point].tag = 0;
    }
}
void build(int point, int l, int r) {
    tree[point].l = l, tree[point].r = r;
    if (l == r) {
        tree[point].len = 1;
        tree[point].num[0] = tree[point].num[1] = tree[point].num[2] = tree[point].num[3] = read();
        tree[point].num[1] *= tree[point].num[1];
    } else {
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(point);
    }
}
void modify(int point, int l, int r, int key) {
    if (l <= tree[point].l && r >= tree[point].r) {
        tree[point].tag += key;
        tree[point].num[1] += tree[point].len * key * key + 2 * key * tree[point].num[0];
        tree[point].num[0] += tree[point].len * key;
        tree[point].num[2] += key;
        tree[point].num[3] += key;
    } else {
        pushdn(point);
        if (l <= mid) modify(lson, l, r, key);
        if (r >= mid + 1) modify(rson, l, r, key);
        pushup(point);
    }
}
int query(int point, int l, int r, int flag) {
    if (l <= tree[point].l && r >= tree[point].r) {
        return tree[point].num[flag];
    } else {
        pushdn(point);
        int ans = init(flag);
        if (l <= mid) deal(ans, query(lson, l, r, flag), flag);
        if (r >= mid + 1) deal(ans, query(rson, l, r, flag), flag);
        return ans;
    }
}
void principle() {
    printf("[query principle]\n");
    printf("input \"opt l r\"\n");
    printf("opt=0 => query the sum of section\n");
    printf("opt=1 => query the sum of section's square\n");
    printf("opt=2 => query the max number of section\n");
    printf("opt=3 => query the min number of section\n");
    printf("l & r => the section [l,r]\n");
}