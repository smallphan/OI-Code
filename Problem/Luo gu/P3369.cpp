#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 2147483647;
vector<int> num;
int n, now, opt;

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        opt = read(), now = read();
        if (opt == 1) {
            num.insert(lower_bound(num.begin(), num.end(), now), now);
        } else if (opt == 2) {
            num.erase(lower_bound(num.begin(), num.end(), now));
        } else if (opt == 3) {
            printf("%d\n", lower_bound(num.begin(), num.end(), now) - num.begin() + 1);
        } else if (opt == 4) {
            printf("%d\n", num[now - 1]);
        } else if (opt == 5) {
            printf("%d\n", *(lower_bound(num.begin(), num.end(), now) - 1));
        } else if (opt == 6) {
            printf("%d\n", *upper_bound(num.begin(), num.end(), now));
        }
    }
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}