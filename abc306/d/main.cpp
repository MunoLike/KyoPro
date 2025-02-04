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
    deque<i64> poisoned, drug;
    rep(i, n) {
        i32 x;
        cin >> x;
        i64 y;
        cin >> y;

        if (x == 0) {
            drug.emplace_back(y);
        } else {
            poisoned.emplace_back(y);
        }
    }

    sort(all(drug), greater<i64>());
    sort(all(poisoned), greater<i64>());

    i64 sum = 0, status = 2;
    rep(i, n) {
        if (status >= 2) {
            if (drug.front() > poisoned.front()) {
                if (drug.size() >= 1) {
                    sum += drug.front();
                    drug.pop_front();
                }
            } else {
                if (poisoned.size() >= 1) {
                    sum += poisoned.front();
                    poisoned.pop_front();
                    --status;
                }
            }
        } else {
            if (drug.size() >= 1) {
                sum += drug.front();
                drug.pop_front();
                ++status;
            }
        }
    }
    cout << sum << endl;
}