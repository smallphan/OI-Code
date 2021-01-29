#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    double x, y, angle;
    bool operator < (const node& data) const {
        return this -> angle < data.angle;
    }
    friend node operator - (const node& fir, const node& sec) {
        return (node) { fir.x - sec.x, fir.y - sec.y, 0 };
    }
    friend double operator ^ (node fir, node sec) {
        return fir.x * sec.y - fir.y * sec.x;
    }
} dot[maxn];
int stk[maxn], top;
int n, fir = 1;
double ans;

inline void input();
inline void deal();
inline void work();
double dis(node, node);

int main() {
    input();
    deal();
    work();
    return 0;
}

inline void input() {
    double x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &dot[i].x, &dot[i].y);
        if ((y < dot[fir].y) || (y == dot[fir].y && x < dot[i].x)) fir = i;
    }
}
inline void deal() {
    swap(dot[1], dot[fir]);
    double x = dot[1].x, y = dot[1].y;
    for (int i = 1; i <= n; i++) {
        dot[i].x -= x;
        dot[i].y -= y;
        dot[i].angle = atan2(dot[i].y, dot[i].x);
    }
    sort(dot + 2, dot + 1 + n);
}
inline void work() {
    stk[++top] = 1;
    stk[++top] = 2;
    for (int i = 3; i <= n; i++) {
        while (top >= 3 && ((dot[stk[top]] - dot[stk[top - 1]]) ^ (dot[i] - dot[stk[top]])) < 0) top--;
        stk[++top] = i;
    }
    stk[++top] = 1;
    for (int i = 1; i <= top - 1; i++) {
        ans += dis(dot[stk[i]], dot[stk[i + 1]]);
    }
    printf("%lf\n", ans);
}
double dis(node fir, node sec) {
    double x = fir.x - sec.x, y = fir.y - sec.y;
    return sqrt(x * x + y * y);
}