#include <cstdio>
#include <algorithm>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define dad  (point >> 1)

using namespace std;

const int maxn = 1e5 + 5;
int n, heap[maxn], size;

inline long long read();
void shiftup(int);
void shiftdn(int);
int top();
void pop();
void push(int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) push(read());
    while (size) printf("%d ", top()), pop();
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void shiftup(int point) {
    if (point == 1) return;
    if (heap[point] > heap[dad]) {
        swap(heap[point], heap[dad]);
        shiftup(dad);
    }
}
void shiftdn(int point) {
    int mark = point;
    if (lson <= size && heap[lson] > heap[mark]) mark = lson;
    if (rson <= size && heap[rson] > heap[mark]) mark = rson;
    if (mark == point) return;
    swap(heap[mark], heap[point]);
    shiftdn(mark);
}
int top() { 
    return  heap[1];
}
void pop() {
    heap[1] = heap[size--];
    shiftdn(1);
}
void push(int data) {
    heap[++size] = data;
    shiftup(size);
}