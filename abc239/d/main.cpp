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

bool is_prime(i32 num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    i32 sqrt_num = sqrt(num) + 1;
    for (i32 k = 3; k <= sqrt_num; ++k) {
        if (num % k == 0) return false;
    }
    return true;
}

int main() {
    vector<bool> prime(400);
    rep(i, 400) {
        prime[i] = is_prime(i);
    }

    i32 a, b, c, d;
    cin >> a >> b >> c >> d;

    bool is_aoki = true;
    for (i32 i = a; i <= b; ++i) {
        // 高橋がどんな数を出してきても素数を作れるか
        bool prime = false;
        for (i32 j = c; j <= d; ++j) {
            i32 sum = i + j;
            prime |= is_prime(sum);
        }
        is_aoki &= prime;  // もし素数がつくれないならここの&でis_aokiがfalseになるはず
    }
    cout << (is_aoki ? "Aoki" : "Takahashi") << endl;
}