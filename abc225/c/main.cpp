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
  i32 N, M;
  cin >> N >> M;
  vector<vector<i64>> area(N, vector<i64>(M)), x(N, vector<i64>(M)), y(N, vector<i64>(M));

  rep(i, N) rep(j, M) cin >> area[i][j];

  rep(i, N) {
    rep(j, M) {
      x[i][j] = (area[i][j] - 1) / 7;
      y[i][j] = (area[i][j] - 1) % 7;
    }
  }

  bool flag = true;
  rep(i, N) {
    rep(j, M) {
      if (0 < i && x[i][j] != x[i - 1][j] + 1) flag = false;
      if (0 < i && y[i][j] != y[i - 1][j]) flag = false;
      if (0 < j && x[i][j] != x[i][j - 1]) flag = false;
      if (0 < j && y[i][j] != y[i][j - 1] + 1) flag = false;
    }
  }

  cout << (flag ? "Yes\n" : "No\n");
}