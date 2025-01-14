#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vvi32 = vector<vector<i32>>;
using vvi64 = vector<vector<i64>>;
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
inline S chmax(S& a, T b) {
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
    string base = "atcoder";

    map<char, i32> mp;
    rep(i, 7) mp[base[i]] = i;
    vector<i32> a(7);
    rep(i, 7) a[i] = mp[s[i]];
    i32 n = 0;
    rep(i, 7) rep(j, i) {
        if (a[j] > a[i]) ++n;
    }
    cout << n << endl;
}