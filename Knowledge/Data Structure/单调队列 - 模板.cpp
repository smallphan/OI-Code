#include <list>
#include <cstdio>

using namespace std;

int n, num;
list <int> lst;

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        num = read();
        while (lst.size() && lst.back() >= num) lst.pop_back();
        lst.push_back(num);
        printf("%d ", lst.front());
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}