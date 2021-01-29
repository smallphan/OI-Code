#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, dp, ans, fir[maxn], sec[maxn];
int tree[maxn];

inline long long read();
namespace treearray {
    int lowbit(int);
    void update(int, int);
    int getmax(int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) fir[i] = sec[i] = read();
    sort(sec + 1, sec + 1 + n);
    int size = unique(sec + 1, sec + 1 + n) - (sec + 1);
    for (int i = 1; i <= n; i++) {
        fir[i] = lower_bound(sec + 1, sec + size + 1, fir[i]) - sec; // [ Discretize ] 离散化
    }
    for (int i = 1; i <= n; i++) {
        dp = treearray::getmax(fir[i] - 1) + 1;
        ans = max(ans, dp);
        treearray::update(fir[i], dp);
    }
    printf("[max lis] %d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
namespace treearray {
    int lowbit(int num) {
        return num & (-num);
    }
    void update(int pos, int data) {
        for (int i = pos; i <= n; i += lowbit(i)) tree[i] = max(tree[i], data);
    }
    int getmax(int pos) {
        int ans = 0;
        for (int i = pos; i; i -= lowbit(i)) ans = max(ans, tree[i]);
        return ans;
    }
}