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
  i32 N;
  cin >> N;
  vector mat_a(N, vector<i32>(N));
  vector mat_b(N, vector<i32>(N));

  rep(i, N) {
    rep(j, N) {
      cin >> mat_a[i][j];
    }
  }

  rep(i, N) {
    rep(j, N) {
      cin >> mat_b[i][j];
    }
  }

  bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
  rep(i, N) {
    rep(j, N) {
      if (mat_a[i][j] == 1 && mat_b[i][j] == 0) {
        flag1 = false;
      }
      if (mat_a[i][j] == 1 && mat_b[N - 1 - j][i] == 0) {
        flag2 = false;
      }
      if (mat_a[i][j] == 1 && mat_b[N - 1 - i][N - 1 - j] == 0) {
        flag3 = false;
      }
      if (mat_a[i][j] == 1 && mat_b[j][N - 1 - i] == 0) {
        flag4 = false;
      }
    }
  }

  cout << (flag1 || flag2 || flag3 || flag4 ? "Yes" : "No") << endl;
}