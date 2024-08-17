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

    i32 N, K;
    cin >> N >> K;
    vector<pair<i32, i32>> meds;
    rep(i, N) {
        i32 a, b;
        cin >> a >> b;
        meds.emplace_back(a, b);
    }

    sort(all(meds));

    i64 sum = 0;
    rep(i, N) {
        sum += meds[i].second;
    }

    if (sum <= K) {
        cout << 1 << '\n';
        return 0;
    }

    i64 day = 0;
    rep(i, N) {
        sum -= meds[i].second;

        if (sum <= K) {
            day = meds[i].first + 1;
            break;
        }
    }

    cout << day << '\n';
}