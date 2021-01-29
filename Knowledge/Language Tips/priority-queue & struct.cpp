#include <queue>
#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int value, point;
    inline bool operator < (const node& data) const {
        return value > data.value; // minheap
        // return value < data.value; // maxheap
    }
};
int n, value, point;
priority_queue <node> heap;

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        value = read(), point = read();
        heap.push((node) { value, point });
    }   
    while (!heap.empty()) {
        node ans = heap.top(); heap.pop();
        printf("[value] %d [point] %d\n", ans.value, ans.point);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}