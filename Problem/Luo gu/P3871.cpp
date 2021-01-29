#include <cstdio>
#include <vector>
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

vector<int> num;
int n, m, now;
char opt[5];

int main() {
    n = read();
    while (n--) {
        now = read();
        num.insert(upper_bound(num.begin(), num.end(), now), now);
    }
    m = read();
    while (m--) {
        scanf("%s", opt + 1);
        if (opt[1] == 'a') {
            now = read();
            num.insert(upper_bound(num.begin(), num.end(), now), now);
        } else printf("%d\n", (num.size() & 1) ? num[num.size() / 2] : num[(num.size() / 2) - 1]);
    }
    return 0;
}