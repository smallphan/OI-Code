#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N, Num[1005];
int DP[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> Num[i];
    }
    memset(DP, 0xf777, sizeof(DP));
    for (int i = 1; i < N; i++) {
        DP[i][i + 1] = 0;
    }
    for (int Len = 3; Len <= N; Len++) {
        for (int L = 1, R = Len; R <= N; L++, R++) {
            for (int Mid = L + 1; Mid <= R - 1; Mid++) {
                DP[L][R] = min(DP[L][R], DP[L][Mid] + DP[Mid][R] + Num[L] * Num[Mid] * Num[R]);
            }
        }
    }
    cout << DP[1][N] << endl;
    return 0;
}
