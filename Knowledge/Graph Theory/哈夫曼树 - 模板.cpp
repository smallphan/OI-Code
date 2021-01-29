#include <queue>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
struct nodefir {
    int value, pos;
    inline bool operator < (const nodefir& data) const {
        return value > data.value;
    }
}; priority_queue <nodefir> heap;
struct nodesec {
    int value, lkid, rkid;
} point[maxn];
int n, cnt, ans, value;

inline long long read();

int main() {
    n = read();
    for (cnt = 1; cnt <= n; cnt++) {
        value = read();
        heap.push((nodefir) { value, cnt });
        point[cnt] = (nodesec) { value, 0, 0 };
    }
    cnt--;
    while (heap.size() != 1) {
        nodefir fir = heap.top(); heap.pop();
        nodefir sec = heap.top(); heap.pop();
        heap.push((nodefir) { fir.value + sec.value, ++cnt });
        point[cnt] = (nodesec) { fir.value + sec.value, fir.pos, sec.pos };
        ans += point[cnt].value;
    }
    printf("[ans] %-3d\n", ans);
    for (int i = 1; i <= cnt; i++) {
        printf("[point] %-3d [value] %-3d [lkid] %-3d [rkid] %-3d\n", i, point[i].value, point[i].lkid, point[i].rkid);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}