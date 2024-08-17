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

  string pattern = "atcoder";
  string S, T;
  i32 S_char_count[26] = {0}, T_char_count[26] = {0};
  i32 S_at = 0, T_at = 0;
  cin >> S >> T;

  rep(i, S.size()) {
    if (S[i] == '@')
      ++S_at;
    else {
      ++S_char_count[S[i] - 'a'];
    }

    if (T[i] == '@')
      ++T_at;
    else {
      ++T_char_count[T[i] - 'a'];
    }
  }

  rep(i, 26) {
    if (S_char_count[i] == T_char_count[i])
      continue;
    else {
      bool flag = false;
      for (char x : pattern) {
        flag |= (char)(i + 'a') == x;
      }
      if (!flag) {
        cout << "No\n";
        return 0;
      }

      if (S_char_count[i] > T_char_count[i]) {
        if (T_at - (S_char_count[i] - T_char_count[i]) >= 0)
          T_at = T_at - (S_char_count[i] - T_char_count[i]);
        else {
          cout << "No\n";
          return 0;
        }
      } else {
        if (S_at - (T_char_count[i] - S_char_count[i]) >= 0)
          S_at = S_at - (T_char_count[i] - S_char_count[i]);
        else {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  cout << "Yes\n";
}