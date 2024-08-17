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
  i32 A[9][9];

  rep(i, 9) {
    rep(j, 9) {
      cin >> A[i][j];
    }
  }

  rep(i, 9) {
    set<i32> contain;
    rep(j, 9) {
      contain.insert(A[i][j]);
    }
    if (contain.size() != 9) {
      cout << "No\n";
      return 0;
    }
  }

  rep(j, 9) {
    set<i32> contain;
    rep(i, 9) {
      contain.insert(A[i][j]);
    }
    if (contain.size() != 9) {
      cout << "No\n";
      return 0;
    }
  }

  rep(i, 3) {
    rep(j, 3) {
      set<i32> contain;
      rep(k, 3) {
        rep(l, 3) {
          contain.insert(A[i * 3 + k][j * 3 + l]);
        }
      }
      if (contain.size() != 9) {
        cout << "No\n";
        return 0;
      }
    }
  }

  cout << "Yes\n";
}