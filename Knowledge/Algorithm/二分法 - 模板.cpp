#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, key, l, r, num[maxn];

inline long long read();
bool check(int);

int main() {
    n = read(), key = read();
    l = 1, r = n;
    for (int i = 1; i <= n; i++) num[i] = read();
    sort(num + 1, num + 1 + n);
    while (l != r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    printf("%d\n", l);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
bool check(int pos) {
    return num[pos] < key;
}