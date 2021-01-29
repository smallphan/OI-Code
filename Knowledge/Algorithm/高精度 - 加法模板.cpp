#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;
struct node {
    int data[maxn];
} fir, sec, ans;
int fircnt, seccnt, cnt;

inline void input(node&, int&);
inline void ouput(node&, int);
inline void reverse(node&, int);
inline void add(node&, node&, node&, int, int, int&);

int main() {
    input(fir, fircnt);
    input(sec, seccnt);
    add(fir, sec, ans, fircnt, seccnt, cnt);
    ouput(ans, cnt);
    return 0;
}

inline void input(node& num, int& cnt) {
    char str = getchar();
    while (str < '0' || str > '9') str = getchar();
    while (str >= '0' && str <= '9') { num.data[++cnt] = str - '0'; str = getchar(); }
}
inline void ouput(node& num, int cnt) {
    for (int i = 1; i <= cnt; i++) printf("%d",num.data[i]);
    printf("\n");
}
inline void reverse(node& num, int cnt) {
    for (int i = 1; i <= (cnt >> 1); i++) {
        swap(num.data[i], num.data[cnt + 1 - i]);
    }
}
inline void add(node& fir, node& sec, node& ans, int fircnt, int seccnt, int& cnt) {
    reverse(fir, fircnt);
    reverse(sec, seccnt);
    cnt = max(fircnt, seccnt);
    for (int i = 1; i <= cnt; i++) {
        ans.data[i] += fir.data[i] + sec.data[i] + (ans.data[i - 1] / 10);
        ans.data[i - 1] %= 10;
    }
    reverse(ans, cnt);
}