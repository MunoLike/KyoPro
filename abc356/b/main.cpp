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
  i32 N, M;
  cin >> N >> M;

  vector<i32> need_nutrition(M);
  rep(i, M) {
    cin >> need_nutrition[i];
  }

  vector<i64> consumed(M, 0);
  rep(i, N) {
    rep(j, M) {
      i32 in;
      cin >> in;
      consumed[j] += in;
    }
  }

  rep(i, M) {
    if (consumed[i] < need_nutrition[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}