#include <cstdio>
#include <algorithm>

#define lson (point << 1)
#define rson (point << 1 | 1)
#define dad  (point >> 1)

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int num[maxn], heapsize;
    bool flag; // [flag] true => maxheap | false => minheap
    void init(bool data) {
        flag = data;
    }
    bool check(int fir, int sec) {
        return flag ? fir > sec : fir < sec;
    }
    void shiftup(int point) {
        if (point == 1) return;
        if (check(num[point], num[dad])) {
            swap(num[point], num[dad]);
            shiftup(dad);
        }
    }
    void shiftdn(int point) {
        int mark = point;
        if (lson <= heapsize && check(num[lson], num[mark])) mark = lson;
        if (rson <= heapsize && check(num[rson], num[mark])) mark = rson;
        if (mark == point) return;
        swap(num[mark], num[point]);
        shiftdn(mark);
    }
    int top() {
        return num[1];
    }
    void pop() {
        num[1] = num[heapsize--];
        shiftdn(1);
    }
    bool empty() {
        return !heapsize;
    }
    int size() {
        return heapsize;
    }
    void push(int data) {
        num[++heapsize] = data;
        shiftup(heapsize);
    }
} maxheap, minheap;
int n, num;

inline long long read();

int main() {
    maxheap.init(true);
    minheap.init(false);
    n = read();
    for (int i = 1; i <= n; i++) {
        num = read();
        maxheap.push(num);
        minheap.push(num);
    }
    
    printf("[maxheap size] %d\n",maxheap.size());
    while (!maxheap.empty()) {
        printf("%d ", maxheap.top());
        maxheap.pop();
    }
    putchar('\n');
    
    printf("[minheap size] %d\n",minheap.size());
    while (!minheap.empty()) {
        printf("%d ", minheap.top());
        minheap.pop();
    }
    putchar('\n');

    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}