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

    vector<string> s(n), t(n);
    map<string, string> to;
    set<string> used;
    rep(i, n) {
        cin >> s[i] >> t[i];
        to.emplace(s[i], t[i]);
    }

    for (string &ss : s) {
        string ns = ss;
        while (!used.contains(ns)) {
            used.emplace(ns);
            auto it = to.find(ns);

            if (it != to.end()) {
                ns = it->second;
                if (ns == ss) {
                    cout << "No\n";
                    return 0;
                }
            } else {
                break;
            }
        }
    }
    cout << "Yes\n";
}