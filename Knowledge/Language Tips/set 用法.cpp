#include <set>
#include <cstdio>

using namespace std;

int n;
set <int> heap;

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) heap.insert(read());
    while (heap.size()) {
        printf("%d ", *heap.begin());
        heap.erase(heap.begin());
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}