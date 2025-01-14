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
    vector<i64> a(n);
    vector<pair<i64, i64>> s;  // 数, 個数
    rep(i, n) cin >> a[i];

    i64 cnt = 0;

    for (i64 i = 0; i < n; ++i) {
        i64 cur = a[i];
        ++cnt;

        if (s.empty()) {
            s.emplace_back(cur, 1);
        } else {
            auto &[val, num] = s.back();

            if (val == cur) {
                if (num + 1 == cur) {
                    cnt -= num+1;
                    s.pop_back();
                } else {
                    ++num;
                }
            } else {
                s.emplace_back(cur, 1);
            }
        }

        cout << cnt << '\n';
    }
}