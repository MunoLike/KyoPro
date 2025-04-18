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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N;
    cin >> N;
    vector<i32> digits;

    while (N > 0) {
        digits.push_back(N % 10);
        N /= 10;
    }

    sort(all(digits));

    i64 mx = 0;
    do {
        for (i32 i = 1; i < digits.size(); ++i) {
            i64 a = 0, b = 0;
            if (digits[0] == 0 || digits[i] == 0) continue;
            for (i32 j = 0; j < i; ++j) {
                a = 10 * a + digits[j];
            }
            for (i32 k = i; k < digits.size(); ++k) {
                b = 10 * b + digits[k];
            }

            i64 mul = a * b;

            chmax(mx, mul);
        }
    } while (next_permutation(all(digits)));

    cout << mx << '\n';
}