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

    queue<string> q;
    map<string, i32> mp;

    mp[s] = 0;
    q.push(s);

    while (!q.empty()) {
        string& f = q.front();
        q.pop();

        if (f == "atcoder") {
            cout << mp[f] << '\n';
            return 0;
        }

        for (i32 i = 1; i < 7; ++i) {
            string nx = f;
            swap(nx[i - 1], nx[i]);
            if (!mp.contains(nx)) {
                q.push(nx);
                mp[nx] = mp[f] + 1;
            }
        }
    }
}