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
    string s;
    cin >> s;
    bool col[7] = {false};

    col[3] |= s[0] == '1';
    col[2] |= s[1] == '1';
    col[4] |= s[2] == '1';
    col[1] |= s[3] == '1';
    col[3] |= s[4] == '1';
    col[5] |= s[5] == '1';
    col[0] |= s[6] == '1';
    col[2] |= s[7] == '1';
    col[4] |= s[8] == '1';
    col[6] |= s[9] == '1';

    if (s[0] == '0') {
        rep(i, 7) {
            if (col[i]) {
                for (i32 j = i + 1; j < 7; ++j) {
                    if (col[j]) {
                        for (i32 k = i + 1; k < j; ++k) {
                            if (!col[k]) {
                                cout << "Yes\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No\n";
}