#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};

template <class S, class T>
inline S prevent_oor(S a, const T b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}

template <class S, class T>
inline S chmax(S &a, T b) {
    if (a < b) {
        a = b;
    }
    return a;
}

inline int64_t div_floor(int64_t a, int64_t b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (a < 0) {
        return (a + 1) / b - 1;
    } else {
        return a / b;
    }
}

inline int64_t div_ceil(int64_t a, int64_t b) {
    return div_floor(a + b - 1, b);
}

int main() {
    i32 N, X;
    cin >> N >> X;
    vector<i32> a(N), b(N);
    rep(i, N) {
        cin >> a[i] >> b[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(10000 + 1));
    dp[0][0] = true;

    rep1(i, N) {
        rep(j, 10000 + 1) {
            if (dp[i - 1][j]) {
                if (j + a[i - 1] <= X) {
                    dp[i][j + a[i - 1]] = true;
                }
                if (j + b[i - 1] <= X) {
                    dp[i][j + b[i - 1]] = true;
                }
            }
        }
    }

    cout << (dp[N][X] ? "Yes\n" : "No\n");
}