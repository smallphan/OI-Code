#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, dp, ans, tree[maxn];
int mis[maxn], ini[maxn];

inline void input();
inline void init();
namespace mode {
    inline int lowbit(int);
    inline void update(int, int);
    inline int query(int);
}

int main() {
    input();
    init();
    for (int i = n; i >= 1; i--) {
        dp = mode::query(mis[i]) + 1;
        ans = max(ans, dp);
        mode::update(mis[i], dp);
    }
    printf("%d\n", ans);
    ans = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        dp = mode::query(mis[i] - 1) + 1;
        ans = max(ans, dp);
        mode::update(mis[i], dp);
    }
    printf("%d\n", ans); 
    return 0;
}

inline void input() {
    while (cin >> mis[++n]);
    n--;
}
inline void init() {
    for (int i = 1; i <= n; i++) ini[i] = mis[i];
    sort(ini + 1, ini + 1 + n);
    int size = unique(ini + 1, ini + 1 + n) - (ini + 1);
    for (int i = 1; i <= n; i++) {
        mis[i] = lower_bound(ini + 1, ini + 1 + size, mis[i]) - ini;
    }
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