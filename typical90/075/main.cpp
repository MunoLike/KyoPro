#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (i32 i = 0; i < (n); i++)
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

vector<i64> prime_factor(i64 n) {
    i64 rem = n;
    vector<i64> ans;
    for (i64 i = 2; i * i <= n; ++i) {
        while (rem % i == 0) {
            ans.emplace_back(i);
            rem /= i;
        }
    }

    if (rem != 1) ans.emplace_back(rem);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 n;
    cin >> n;

    auto factors = prime_factor(n);
    i64 opcnt = 0;
    for (i32 i = 0; i <= 6; ++i) {  // 2^x >= 素因数分解で出てきた数の個数。最大でlog_2 (log_2 n) = 5.32...個
        if (1U << i >= factors.size()) {
            opcnt = i;
            break;
        }
    }

    cout << opcnt << endl;
}