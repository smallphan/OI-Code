#include <queue>
#include <cstdio>

namespace ios {
    inline long long read() {
        long long ans = 0, tag = 1; char str = getchar();
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
    template<typename type> inline void write(type ans) {
        if (ans < 0) putchar('-'), ans = -ans;
        if (ans > 9) write(ans / 10);
        putchar(ans % 10 + '0');
    }
}

using namespace std;
using namespace ios;

const int maxn = 1e4 + 5;
struct nodef {
    int a, b, c;
    inline int f(int x) {
        return a * x * x + b * x + c;
    }
} func[maxn];
struct nodes {
    int val, pos;
    inline bool operator < (const nodes& data) const {
        return val > data.val;
    }
}; priority_queue<nodes> heap;
int n, m, cnt[maxn];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        func[i] = (nodef) { read(), read(), read() };
        heap.push((nodes) { func[i].f(++cnt[i]), i });
    }
    while (m--) {
        int val = heap.top().val, pos = heap.top().pos;
        heap.pop();
        write(val), putchar(' ');
        heap.push((nodes) { func[pos].f(++cnt[pos]), pos });
    }
    return 0;
}