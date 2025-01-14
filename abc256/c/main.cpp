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

template <class T>
inline bool isin(T val, T lower, T upper) {
    return lower <= val && val < upper;
}

inline int64_t div_ceil(int64_t a, int64_t b) {
    return div_floor(a + b - 1, b);
}

int main() {
    i32 h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    i32 ans = 0;
    for (i32 a = 1; a <= 28; ++a) {
        for (i32 b = 1; b <= 28; ++b) {
            for (i32 d = 1; d <= 28; ++d) {
                for (i32 e = 1; e <= 28; ++e) {
                    i32 c = h1 - a - b;
                    i32 f = h2 - d - e;
                    i32 g = w1 - a - d;
                    i32 h = w2 - b - e;
                    i32 i = w3 - c - f;
                    if (min({c, f, g, h, i}) > 0 and g + h + i == h3) ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}