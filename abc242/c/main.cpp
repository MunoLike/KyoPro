#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

inline void add(i64 &x, i64 y) {
    x += y;
    x %= 998244353L;
}

int main() {
    i64 n;
    cin >> n;
    vector<vector<modint998244353>> dp(n, vector<modint998244353>(9));

    rep(i, 9) dp[0][i] = 1;

    for (i32 i = 1; i < n; ++i) {
        rep(j, 9) {
            if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j];
            if (j + 1 <= 8) dp[i][j] += dp[i - 1][j + 1];
        }
    }

    modint998244353 ans = 0;
    rep(i, 9) ans += dp[n - 1][i];

    cout << ans.val() << endl;
}