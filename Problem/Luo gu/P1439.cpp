#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, dp, ans, fir[maxn], sec[maxn];
int map[maxn], tree[maxn];

inline long long read();
inline void input(int*);
namespace mode {
    inline int lowbit(int);
    inline void update(int, int);
    inline int query(int);
}

int main() {
    n = read();
    input(fir), input(sec);
    for (int i = 1; i <= n; i++) map[fir[i]] = i;
    for (int i = 1; i <= n; i++) sec[i] = map[sec[i]];
    for (int i = 1; i <= n; i++) {
        dp = mode::query(sec[i] - 1) + 1;
        ans = max(ans, dp);
        mode::update(sec[i], dp);
    }
    printf("%d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void input(int* num) {
    for (int i = 1; i <= n; i++) num[i] = read();
}
namespace mode {
    inline int lowbit(int num) {
        return num & (-num);
    }
    inline void update(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) tree[i] = max(tree[i], val);
    }
    inline int query(int pos) {
        int ans = 0;
        for (int i = pos; i >= 1; i -= lowbit(i)) ans = max(ans, tree[i]);
        return ans;
    }
}