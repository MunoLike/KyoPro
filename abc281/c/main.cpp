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
    i64 N, T;
    cin >> N >> T;
    vector<i64> A(N), psum(N + 1, 0);
    rep(i, N) cin >> A[i];

    for (i32 i = 1; i <= N; ++i) psum[i] = psum[i - 1] + A[i - 1];

    i64 sum = reduce(all(A));
    i64 residue = T % sum;

    i32 idx = 0;
    rep(i, N) {
        if (psum[i] <= residue && residue <= psum[i + 1]) {
            idx = i;
        }
    }
    cout << idx + 1 << ' ' << residue - psum[idx] << '\n';
}