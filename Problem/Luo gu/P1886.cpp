#include <list>
#include <cstdio>

using namespace std;

const int maxn = 1e6 + 5;
int n, k, num[maxn];
list <int> lst;

inline long long read();

int main() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    for (int i = 1; i <= n; i++) {
        while (lst.size() && lst.front() <= i - k) lst.pop_front();
        while (lst.size() && num[lst.back()] >= num[i]) lst.pop_back();
        lst.push_back(i);
        if (i >= k) printf("%d ", num[lst.front()]);
    }
    puts("");
    lst.clear();
    for (int i = 1; i <= n; i++) {
        while (lst.size() && lst.front() <= i - k) lst.pop_front();
        while (lst.size() && num[lst.back()] <= num[i]) lst.pop_back();
        lst.push_back(i);
        if (i >= k) printf("%d ", num[lst.front()]);
    }
    puts("");
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}