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
    i32 Q;
    cin >> Q;
    deque<pair<i64, i64>> dq;
    rep(i, Q) {
        i64 op, x, c;
        cin >> op;
        if (op == 1) {
            cin >> x >> c;
            if (!dq.empty() && dq.back().first == x) {
                dq.back().second += c;
            } else {
                dq.emplace_back(x, c);
            }
        } else {
            cin >> c;
            i64 sum = 0;
            while (0 < c) {
                if (dq.front().second <= c) {
                    sum += dq.front().first * dq.front().second;
                    c -= dq.front().second;
                    dq.pop_front();
                } else {
                    sum += dq.front().first * c;
                    dq.front().second -= c;
                    c = 0;
                }
            }
            cout << sum << '\n';
        }
    }
}