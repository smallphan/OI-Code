#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long li;
const int maxn = 1e5 + 5, mod = 1e8 - 3;
li n, ans, a[maxn], b[maxn], c[maxn];
li init[maxn], tree[maxn];

inline long long read();
inline void input(li*);
namespace mode {
    inline li lowbit(li);
    inline void update(li, li);
    inline li query(li);
}

int main() {
    n = read();
    input(a), input(b);
    for (int i = 1; i <= n; i++) c[a[i]] = i;
    for (int i = 1; i <= n; i++) b[i] = c[b[i]];
    for (int i = 1; i <= n; i++) {
        ans += mode::query(n) - mode::query(b[i]);
        mode::update(b[i], 1);
    }
    printf("%lld\n", ans % mod);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void input(li* num) {
    for (int i = 1; i <= n; i++) num[i] = init[i] = read();
    sort(init + 1, init + 1 + n);
    int size = unique(init + 1, init + 1 + n) - (init + 1);
    for (int i = 1; i <= n; i++) {
        num[i] = lower_bound(init + 1, init + 1 + size, num[i]) - init;
    }
}
namespace mode {
    inline li lowbit(li num) {
        return num & (-num);
    }
    inline void update(li pos, li val) {
        for (li i = pos; i <= n; i += lowbit(i)) tree[i] += val;
    }
    inline li query(li pos) {
        li ans = 0;
        for (li i = pos; i >= 1; i -= lowbit(i)) ans += tree[i];
        return ans;
    }
}