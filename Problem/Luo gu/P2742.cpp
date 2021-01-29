#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    double x, y, ang;
    bool operator < (const node& data) const {
        return this -> ang < data.ang;
    }
    friend node operator - (const node& fir, const node& sec) {
        return (node) { fir.x - sec.x, fir.y - sec.y, 0 };
    }
    friend double operator ^ (node fir, node sec) {
        return fir.x * sec.y - sec.x * fir.y;
    }
} dot[maxn];
int stack[maxn], top;
int n, start = 1;
double ans;

inline void input();
double dis(node, node);

int main() {
    input();
    sort(dot + 2, dot + 1 + n);
    dot[1].x = dot[1].y = 0;
    stack[1] = 1; 
    stack[2] = 2;
    stack[3] = 3;
    top = 3;
    for (int i = 4; i <= n; i++) {
        while (top >= 3 && ((dot[stack[top]] - dot[stack[top - 1]]) ^ (dot[i] - dot[stack[top]])) < 0) top--;
        stack[++top] = i;
    }
    for (int i = 1; i <= top - 1; i++) {
        ans += dis(dot[stack[i]], dot[stack[i + 1]]);
    }
    ans += dis(dot[stack[top]], dot[stack[1]]);
    printf("%.2lf\n", ans);
    return 0;
}

inline void input() {
    double x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &dot[i].x, &dot[i].y);
        if ((dot[i].y < dot[start].y) || (dot[i].y == dot[start].y && dot[i].x < dot[start].x)) start = i;
    }
    swap(dot[1], dot[start]);
    for (int i = 2; i <= n; i++) {
        dot[i].x -= dot[1].x;
        dot[i].y -= dot[1].y;
        dot[i].ang = atan2(dot[i].y, dot[i].x);
    }
}
double dis(node fir, node sec) {
    double x = fir.x - sec.x, y = fir.y - sec.y;
    return sqrt(x * x + y * y);
}