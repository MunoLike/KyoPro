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

    i32 N, K;
    cin >> N >> K;

    vector<i32> R(N);
    rep(i, N) cin >> R[i];

    vector<i32> A(N, 1);

    while (true) {
        i32 sum = reduce(all(A));
        if (sum % K == 0) {
            rep(i, N) { cout << A[i] << ' '; }
            cout << endl;
        }

        for (i32 i = A.size() - 1; 0 <= i; --i) {
            if (A[i] < R[i]) {
                ++A[i];
                break;
            } else {
                if (i == 0 && A[0] == R[0]) return 0;
                for (i32 j = i; j < N; ++j) A[j] = 1;
            }
        }
    }
}