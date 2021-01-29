#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N, Num, Sum[1005];
int DP[1005][1005];

inline int GetSum(int l, int r) { return Sum[r] - Sum[l - 1]; }
int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> Num;
        Sum[i] = Sum[i - 1] + Num;
    }
    memset(DP, 0xf777, sizeof(DP));
    for (int i = 1; i <= N; i++) {
        DP[i][i] = 0;
    }
    for (int Len = 2; Len <= N; Len++) {
        for (int L = 1, R = Len; R <= N; L++, R++) {
            for (int Mid = L; Mid < R; Mid++) {
                DP[L][R] = min(DP[L][R], DP[L][Mid] + DP[Mid + 1][R] + GetSum(L, R));
            }
        }
    }
    cout << DP[1][N] << endl;
    return 0;
}
