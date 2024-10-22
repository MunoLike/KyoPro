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
    string S;
    cin >> S;

    vector<bool> flag(26);
    i32 depth = 0;
    vector<vector<i32>> appear(S.size());
    stack<i32> dfsa;
    rep(i, S.size()) {
        if (S[i] == '(') {
            depth++;
        } else if (S[i] == ')') {
            for (auto &&c : appear[depth]) {
                flag[c - 'a'] = false;
            }
            appear[depth].clear();
            depth--;
        } else {
            if (flag[S[i] - 'a']) {
                cout << "No\n";
                return 0;
            }

            flag[S[i] - 'a'] = true;
            appear[depth].emplace_back(S[i]);
        }
    }

    cout << "Yes\n";
}