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
    i32 N, M;
    cin >> N >> M;

    vector<pair<i32, i32>> place(2 * N, {0, 0});

    rep(i, 2 * N) {
        place[i].second = i;
    }

    vector<string> hand(N);
    rep(i, 2 * N) {
        cin >> hand[i];
    }

    rep(i, M) {
        rep(j, N) {
            char a = hand[place[2 * j - 1].second][i];
            char b = hand[place[2 * j].second][i];

            if ((a == 'G' && b == 'C') || (a == 'C' && b == 'P') && (a == 'P' && b == 'G')) {
                ++place[2 * j - 1].first;
            } else if ((b == 'G' && a == 'C') || (b == 'C' && a == 'P') && (b == 'P' && a == 'G')) {
                ++place[2 * j].first;
            }
        }
        sort(all(place), [](auto lhs, auto rhs) {
            if (lhs.first > rhs.first) {
                return true;
            } else if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
            } else {
                return false;
            }
        });
    }

    for (auto [_, idx] : place) {
        cout << idx + 1 << '\n';
    }
}