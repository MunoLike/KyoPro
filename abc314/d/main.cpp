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
    i32 n, q;
    string s;
    cin >> n >> s >> q;

    vector<pair<i32, char>> status(n);  // 更新時刻, 文字
    rep(i, n) {
        status[i].second = s[i];
    }

    pair<i32, i32> last_full_modify = {-1, 0};  // 更新時刻, 更新種別
    rep(i, q) {
        i32 t, x;
        char c;
        cin >> t >> x >> c;
        switch (t) {
            case 1:
                status[x - 1].first = i;
                status[x - 1].second = c;
                break;
            case 2:
                last_full_modify.first = i;
                last_full_modify.second = 2;
                break;
            case 3:
                last_full_modify.first = i;
                last_full_modify.second = 3;
                break;
            default:
                break;
        }
    }

    rep(i, n) {
        if (last_full_modify.first == -1 or last_full_modify.first < status[i].first) {
            cout << status[i].second;
        } else if (last_full_modify.second == 2) {
            cout << (char)tolower(status[i].second);
        } else {
            cout << (char)toupper(status[i].second);
        }
    }
}