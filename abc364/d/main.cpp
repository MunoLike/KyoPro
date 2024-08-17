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

template <class S, class T>
inline S chmin(S &a, T b) {
    if (a > b) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 N, Q;
    cin >> N >> Q;
    vector<i64> A(N);

    rep(i, N) cin >> A[i];

    sort(all(A));

    vector<i64> A_inv(A);
    rep(i, N) A_inv[i] = -A_inv[i];

    rep(i, Q) {
        i64 b, k;
        cin >> b >> k;

        --k;

        i64 len_r = 0, len_l = 0;
        auto idx = lower_bound(all(A), b);

        cout << (idx - A.begin()) << endl;

        if ((idx - A.begin()) + k < N) {
            len_r = *(idx + k) - b;
        }
        if ((idx - A.begin()) - k >= 0) {
            len_l = b - *(idx - k);
        }

        cout << max(len_r, len_l) << '\n';
    }
}