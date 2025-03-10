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
    i32 n;
    cin >> n;
    vector<i64> a(n);
    rep(i, n) cin >> a[i];
    i32 q;
    cin >> q;

    i64 all_value = 0;
    vector<i32> is_assigned(n);
    i32 assigned_cnt = 0;
    rep(i, q) {
        i64 c, in, x;
        cin >> c;
        switch (c) {
            case 1:
                cin >> x;
                all_value = x;
                ++assigned_cnt;
                break;
            case 2:
                cin >> in >> x;
                --in;
                if (is_assigned[in] < assigned_cnt) {
                    a[in] = all_value + x;
                    is_assigned[in] = assigned_cnt;
                } else {
                    a[in] += x;
                }
                break;
            case 3:
                cin >> in;
                --in;
                if (is_assigned[in] < assigned_cnt) {
                    cout << all_value << '\n';
                } else {
                    cout << a[in] << '\n';
                }
                break;
            default:
                break;
        }
    }
}