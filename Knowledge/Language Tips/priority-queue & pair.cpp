#include <queue>
#include <cstdio>

using namespace std;

priority_queue < pair <int, int> > heap;
int n, value, point;

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        value = read(), point = read();
        heap.push(make_pair(value, point));
    }
    for (int i = 1; i <= n; i++) {
        value = heap.top().first;
        point = heap.top().second;
        heap.pop();
        printf("[value] %d [point] %d\n", value, point);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}