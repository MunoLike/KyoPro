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
  i64 N, M, T;
  cin >> N >> M >> T;

  vector<i64> room(N, 0);
  vector<i64> bonus(N, 0);
  rep(i, N - 1) {
    cin >> room[i];
  }
  rep(i, M) {
    i64 idx, b;
    cin >> idx >> b;
    --idx;
    bonus[idx] = b;
  }

  rep(i, N - 1) {
    T += bonus[i];
    T -= room[i];
    if (T <= 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}