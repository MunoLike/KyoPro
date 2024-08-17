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
    string X;
    i32 N;
    cin >> X >> N;

    vector<string> names(N);
    rep(i, N) cin >> names[i];

    i32 order[26];
    rep(i, X.size()) {
        order[X[i] - 'a'] = i;
    }

    sort(all(names), [&](const auto lhs, const auto rhs) {
        i32 len = min(lhs.size(), rhs.size());
        rep(i, len) {
            if (lhs[i] != rhs[i]) {
                return order[lhs[i] - 'a'] < order[rhs[i] - 'a'];
            }
        }
        return lhs.size() < rhs.size();
    });

    rep(i, N) cout << names[i] << '\n';
}