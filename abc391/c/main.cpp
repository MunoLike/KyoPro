#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using mint = modint998244353;
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
    i64 n, q;
    cin >> n >> q;
    vector<i32> multi_bird_house(n, 1);  // 巣番号, 鶏の数
    vector<i32> cur_pos(n);              // 現在の鳥の場所
    i64 cnt = 0;
    rep(i, n) {
        cur_pos[i] = i;
    }

    rep(i, q) {
        i32 c, p, h;
        cin >> c;
        switch (c) {
            case 1:
                cin >> p >> h;
                --p, --h;
                --multi_bird_house[cur_pos[p]];
                if (multi_bird_house[cur_pos[p]] == 1) --cnt;

                ++multi_bird_house[h];
                cur_pos[p] = h;
                if (multi_bird_house[h] == 2) ++cnt;
                break;
            case 2:
                cout << cnt << '\n';
                break;
            default:
                break;
        }
    }
}