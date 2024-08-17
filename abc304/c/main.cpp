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

i32 calc_dist(const pair<i32, i32>& p1, const pair<i32, i32>& p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
    i32 N, D;
    cin >> N >> D;

    vector<bool> is_infected(N);
    vector<pair<i32, i32>> person(N);

    rep(i, N) {
        cin >> person[i].first >> person[i].second;
    }

    bool has_infected = false;
    set<i32> rescent_infected = {
        0,
    };
    is_infected[0] = true;
    do {
        set<i32> new_infected;
        has_infected = false;
        for (auto p : rescent_infected) {
            for (i32 i = 0; i < person.size(); ++i) {
                if (i == p || is_infected[i]) continue;

                if (D * D >= calc_dist(person[p], person[i])) {
                    has_infected = true;
                    is_infected[i] = true;
                    new_infected.emplace(i);
                }
            }
        }
        rescent_infected = new_infected;
    } while (has_infected);

    rep(i, N) {
        cout << (is_infected[i] ? "Yes" : "No") << '\n';
    }
}