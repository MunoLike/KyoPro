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
    i32 n, m;
    cin >> n >> m;
    vector<i64> l(n);
    rep(i, n) cin >> l[i];

    i64 ng = ranges::max(l) - 1, ok = 1e15;
    auto f = [&](i64 w) {
        i64 line = 0, rem = 0;
        rep(i, n) {
            if (rem - (l[i] + 1) >= 0) {
                rem -= l[i] + 1;
            } else {
                rem = w - l[i];  // 残りが足りなくなったら残りの文字数を更新
                //if (rem < 0) return false;
                ++line;
            }
        }
        return line <= m;
    };
    while (abs(ng - ok) > 1) {
        i64 mid = (ng + ok) / 2;
        if (f(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}