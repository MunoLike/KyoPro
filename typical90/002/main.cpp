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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i32 n;
    cin >> n;
    for (u32 line = 0; line < (1U << n); ++line) {
        i32 cnt = 0;
        bool flag = true;
        for (i32 i = n - 1; i >= 0; --i) {
            if (((line >> i) & 1U) == 0) {
                ++cnt;
            } else {
                --cnt;
            }
            if (cnt < 0) {
                flag = false;
                break;
            }
        }
        if (flag and cnt == 0) {
            for (i32 i = n - 1; i >= 0; --i) {
                if (((line >> i) & 1U) == 0) {
                    cout << '(';
                } else {
                    cout << ')';
                }
            }
            cout << endl;
        }
    }
}