#include <queue>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int val, pos;
    bool operator < (const node& data) const {
        return val > data.val;
    }
}; priority_queue <node> heap;
int n, a[maxn], b[maxn], cnt[maxn];

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    for (int i = 1; i <= n; i++) heap.push((node) { a[i] + b[++cnt[i]], i });
    for (int i = 1; i <= n; i++) {
        node now = heap.top();
        printf("%d ", now.val), heap.pop();
        if (++cnt[now.pos] <= n) heap.push((node) { a[now.pos] + b[cnt[now.pos]], now.pos });
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}