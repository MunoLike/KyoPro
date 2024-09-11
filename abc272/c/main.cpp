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
inline S chmax(S& a, T b) {
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

void replace_max(vector<i64>& a, i64 in) {
    if (a.size() < 2) {
        a.emplace_back(in);
        return;
    } else {
        a.emplace_back(in);
        sort(all(a), greater());
        a.pop_back();
    }
}

int main() {
    i32 N;
    cin >> N;
    vector<i64> A(N), even, odd;
    rep(i, N) cin >> A[i];

    rep(i, N) {
        if (A[i] % 2 == 0) {
            even.emplace_back(A[i]);
        } else {
            odd.emplace_back(A[i]);
        }
    }

    sort(all(even), greater());
    sort(all(odd), greater());

    i64 sum = -1;

    if (even.size() >= 2) chmax(sum, even[0] + even[1]);
    if (odd.size() >= 2) chmax(sum, odd[0] + odd[1]);
    cout << sum << endl;
}