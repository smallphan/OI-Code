// priority_queue [function]
// heap.top()
// heap.pop()
// heap.size()
// heap.empty()
// heap.push(typename)

#include <queue>
#include <cstdio>

using namespace std;

int num[10] = {9, 2, 3, 1, 8, 4, 7, 5, 0, 6};
priority_queue <int> maxheap;
priority_queue <int> minheap;

int main() {
    for (int i = 0; i <= 9; i++) {
        maxheap.push(num[i]);
        minheap.push(-num[i]);
    }
    printf("[maxheap]\n");
    while (!maxheap.empty()) {
        printf("%d ", maxheap.top()); 
        maxheap.pop();
    }
    printf("\n[minheap]\n");
    while (!minheap.empty()) {
        printf("%d ", -minheap.top()); 
        minheap.pop();
    }
    return 0;
}