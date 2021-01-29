#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 3e4 + 5;
ll n, ans, num[maxn], ini[maxn], tree[maxn];
ll cnt[2][maxn];

inline long long read();
namespace array {
    inline int lowbit(int);
    void update(int, ll);
    ll profix(int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) num[i] = ini[i] = read();
    sort(ini + 1, ini + 1 + n);
    int size = unique(ini + 1, ini + 1 + n) - (ini + 1);
    for (int i = 1; i <= n; i++) {
        num[i] = lower_bound(ini + 1, ini + size + 1, num[i]) - ini;
    }
    for (int i = 1; i <= n; i++) {
        cnt[0][i] = array::profix(num[i] - 1);
        array::update(num[i], 1); 
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n; i >= 1; i--) {
        cnt[1][i] = array::profix(n) - array::profix(num[i]);
        array::update(num[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        ans += cnt[0][i] * cnt[1][i];
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
namespace array {
    inline int lowbit(int num) {
        return num & (-num);
    }
    void update(int pos, ll data) {
        for (int i = pos; i <= n; i += lowbit(i)) tree[i] += data; 
    }
    ll profix(int pos) {
        ll ans = 0;
        for (int i = pos; i >= 1; i -= lowbit(i)) ans += tree[i];
        return ans;
    }
}