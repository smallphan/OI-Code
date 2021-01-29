#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
struct node {
    int l, r, pos;
    bool operator < (const node& data) const {
        return r < data.r;
    }
} query[maxn];
int n, m, num[maxn], tree[maxn];
int ans[maxn], pos[maxn], cnt = 1;

inline long long read();
namespace mode {
    inline int lowbit(int);
    inline void update(int, int);
    inline int query(int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    m = read();
    for (int i = 1; i <= m; i++) {
        query[i] = (node) { read(), read(), i };
    }
    sort(query + 1, query + 1 + m);
    for (int i = 1; i <= n; i++) {
        if (pos[num[i]]) mode::update(pos[num[i]], -1);
        mode::update(i, 1), pos[num[i]] = i;
        while (query[cnt].r == i) {
            ans[query[cnt].pos] = mode::query(i) - mode::query(query[cnt].l - 1);
            cnt++;
        }
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
namespace mode {
    inline int lowbit(int num) {
        return num & (-num);
    }
    inline void update(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) tree[i] += val;
    }
    inline int query(int pos) {
        int ans = 0;
        for (int i = pos; i >= 1; i -= lowbit(i)) ans += tree[i];
        return ans;
    }
}