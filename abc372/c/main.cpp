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
    i32 N, Q;
    string S;
    cin >> N >> Q >> S;

    i32 count = 0;

    for (i32 i = 0; i < N - 2; ++i) {
        i32 j = 0;
        bool flag = true;
        for (auto c : {'A', 'B', 'C'}) {
            flag &= S[i + j] == c;
            ++j;
        }
        count += flag;
    }

    S = ".." + S + "..";

    rep(i, Q) {
        i32 X;
        char C;
        cin >> X >> C;

        X = X - 1 + 2;

        bool flag = false;
        for (i32 i = -2; i <= 0; ++i) {
            i32 start = X + i;
            if (S[start] == 'A' && S[start + 1] == 'B' && S[start + 2] == 'C') {
                flag = true;
            }
        }
        count -= flag;

        S[X] = C;

        flag = false;
        for (i32 i = -2; i <= 0; ++i) {
            i32 start = X + i;
            if (S[start] == 'A' && S[start + 1] == 'B' && S[start + 2] == 'C') {
                flag = true;
            }
        }
        count += flag;
        cout << count << '\n';
    }
}