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
    vector<pair<i64, i64>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;

    vector<pair<i64, i64>> diff_list;
    i64 cnt = 0;
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            diff_list.emplace_back(p[i].first - p[j].first, p[i].second - p[j].second);
        }
    }

    rep(i, diff_list.size()) {
        bool flag = true;
        for (i32 j = diff_list.size() - 1; i < j; --j) {
            i64 cross = diff_list[i].first * diff_list[j].second - diff_list[i].second * diff_list[j].first;

            if (cross == 0 and (signbit(diff_list[i].first) == signbit(diff_list[j].first) and signbit(diff_list[i].second) == signbit(diff_list[j].second))) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++cnt;
        }
    }
    cout << cnt << endl;
}