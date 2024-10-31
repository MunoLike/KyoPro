#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vvi32 = vector<vector<i32>>;
using vvi64 = vector<vector<i64>>;
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
    i32 h1, w1, h2, w2;
    cin >> h1 >> w1;
    vvi32 a1(h1, vi32(w1));
    rep(i, h1) rep(j, w1) cin >> a1[i][j];
    cin >> h2 >> w2;
    vvi32 a2(h2, vi32(w2));
    rep(i, h2) rep(j, w2) cin >> a2[i][j];

    for (u32 h = 0; h < (1U << h1); ++h) {
        for (u32 w = 0; w < (1U << w1); ++w) {
            if (popcount(h) == h2 and popcount(w) == w2) {
                bool flag = true;
                u32 k = 0;
                rep(i, h1) {
                    rep(j, w1) {
                        if (h & (1U << i) and w & (1U << j)) {
                            // cout << "a1[" << i << "][" << j << "] a2[" << k / w2 << "][" << k % w2 << "]" << endl;
                            if (a1[i][j] != a2[k / w2][k % w2]) flag = false;
                            ++k;
                        }
                    }
                }
                if (flag) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
}