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
    i32 N;
    i64 K;
    cin >> N >> K;
    vector<i64> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<bool> dpA(N), dpB(N);
    dpA[0] = dpB[0] = true;
    rep1(j, N - 1) {
        if (dpA[j - 1]) {
            if (abs(A[j - 1] - A[j]) <= K) dpA[j] = true;
            if (abs(A[j - 1] - B[j]) <= K) dpB[j] = true;
        }
        if (dpB[j - 1]) {
            if (abs(B[j - 1] - A[j]) <= K) dpA[j] = true;
            if (abs(B[j - 1] - B[j]) <= K) dpB[j] = true;
        }
    }

    cout << (dpA[N - 1] | dpB[N - 1] ? "Yes" : "No") << endl;
}