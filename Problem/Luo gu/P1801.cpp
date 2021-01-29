#include <queue>
#include <cstdio>

using namespace std;

const int maxn = 2e5 + 5;
int m, n, cnt = 1, get, add[maxn];
priority_queue <int, vector<int>, greater<int> > minh;
priority_queue <int> maxh;

inline long long read();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) add[i] = read();
    for (int i = 1; i <= m; i++) {
        get = read();
        for (int j = cnt; j <= get; j++) {
            maxh.push(add[j]);
            if (maxh.size() == i) minh.push(maxh.top()), maxh.pop();
        }
        cnt = get + 1;
        printf("%d\n", minh.top());
        maxh.push(minh.top()), minh.pop();
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}