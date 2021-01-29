#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
vector <int> num;
int n, now;

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        now = read();
        num.insert(upper_bound(num.begin(), num.end(), now), now);
        if (i % 2) printf("%d\n", num[i / 2]);
    }   
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}