#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
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

int main() {
    i32 n;
    cin >> n;

    vector<i64> t(n + 1), x(n + 1), y(n + 1);
    for (i32 i = 1; i < n + 1; ++i) cin >> t[i] >> x[i] >> y[i];

    rep(i, n) {
        i64 diff = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        i64 time_diff = t[i + 1] - t[i];

        if (time_diff < diff or time_diff % 2 != diff % 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}