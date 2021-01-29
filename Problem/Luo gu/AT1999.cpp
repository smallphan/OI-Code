#include <cstdio>
#include <algorithm>

namespace ips {
    inline long long read() {
        char str = getchar(); long long ans = 0, tag = 1;
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
}

using namespace ips;
using namespace std;

const int maxn = 1e5 + 5;

int n, num[maxn];

inline bool cmp(int, int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    sort(num + 1, num + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (i + 1 > num[i + 1]) {
            int j;
            while (num[i + j + 1] == i && ++j);
            if (((num[i] - i) & 1) || (j & 1)) puts("First");
            else puts("Second");
            break;
        }
    }
    return 0;
}

inline bool cmp(int f, int s) {
    return f > s;
}