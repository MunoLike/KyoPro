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
    i32 N;
    cin >> N;

    unordered_map<i32, i32> l_x, r_x;
    vector<pair<i32, i32>> vertices_in;
    rep(i, N) {
        i32 x, y;
        cin >> x >> y;
        vertices_in.emplace_back(x, y);
    }

    string S;
    cin >> S;

    rep(i, N) {
        auto vert = vertices_in[i];
        if (S[i] == 'L') {
            auto res = l_x.insert({vert.second, vert.first});
            if (!res.second) {
                res.first->second = max(res.first->second, vert.first);  // 存在したものの２つめ=x座標
            }
        } else {
            auto res = r_x.insert({vert.second, vert.first});
            if (!res.second) {
                res.first->second = min(res.first->second, vert.first);
            }
        }
    }

    for (auto [y, lx] : l_x) {
        auto res = r_x.find(y);
        if (res != r_x.end()) {
            if (lx < res->second) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
}