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
    i32 N;
    cin >> N;

    map<string, pair<i64, i64>> poems;

    rep(i, N) {
        string S;
        i64 T;
        cin >> S >> T;

        if (!poems.contains(S)) {
            poems.emplace(S, make_pair(i + 1, T));
        }
    }

    vector<pair<i64, i64>> scores;
    for (auto [x, y] : poems) {
        scores.emplace_back(y);
    }

    sort(all(scores), [](auto lhs, auto rhs) { if (lhs.second > rhs.second){return true;}else if(lhs.second == rhs.second){return lhs.first<rhs.first;}else{return false;} });

    cout << scores[0].first << '\n';
}