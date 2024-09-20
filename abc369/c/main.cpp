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
const string lrud("URDL");

template <class S, class T>
inline S prevent_oor(S a, const T b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}

template <class S, class T>
inline bool is_in(const T lower, S a, const T upper) {
    return a < upper && lower <= a;
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
    cout.tie(nullptr);

    i32 N;
    cin >> N;
    vector<i32> A(N), D(N - 1);
    rep(i, N) cin >> A[i];
    rep(i, N - 1) D[i] = A[i + 1] - A[i];

    i64 cont = 0, num = 0;
    // 区間内に2以上数が含まれている場合の数え上げ
    for (i32 i = 0; i < D.size();) {
        i64 j = i;
        while (j < D.size() && D[i] == D[j]) ++j;
        i64 n = j - i;           // n+1 注目している連続した区間に含まれている数の個数
        num += (n + 1) * n / 2;  // 区間に含まれている数を2つ選んでできる区間の数.
        i = j;
    }

    cout << num + N << endl;  // 数1つで等差数列なので+Nする．
}