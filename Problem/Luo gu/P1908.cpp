#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5e5 + 5;
int n, num[maxn], init[maxn], tree[maxn];
long long ans;

inline long long read();
namespace mode {
    inline int lowbit(int);
    inline void update(int, int);
    inline int query(int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) num[i] = init[i] = read();
    sort(init + 1, init + 1 + n);
    int size = unique(init + 1, init + 1 + n) - (init + 1);
    for (int i = 1; i <= n; i++) {
        num[i] = lower_bound(init + 1, init + size + 1, num[i]) - init;
    }
    for (int i = 1; i <= n; i++) {
        ans += mode::query(n) - mode::query(num[i]);
        mode::update(num[i], 1);
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