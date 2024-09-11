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
    i32 N;
    cin >> N;

    vector<i32> x(N), y(N);
    unordered_map<i32, vector<pair<i32, char>>> person;  // y, x座標, [L|R]
    rep(i, N) {
        cin >> x[i] >> y[i];
    }

    string S;
    cin >> S;
    rep(i, N) {
        person[y[i]].emplace_back(x[i], S[i]);
    }

    for (auto [y, ps] : person) {
        set<char> dirs;
        i32 rmn = INT32_MAX, lmx = INT32_MIN;
        for (auto [x, dir] : ps) {
            dirs.emplace(dir);
            if (dir == 'L') {
                chmax(lmx, x);
            } else {
                chmin(rmn, x);
            }
        }
        if (dirs.size() == 2 && rmn < lmx) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}