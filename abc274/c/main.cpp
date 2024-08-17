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
  i32 N;
  cin >> N;

  vector<i32> parent(N * 2 + 2, 0);

  for (i32 i = 1; i <= N; ++i) {
    i32 A;
    cin >> A;
    parent[i * 2] = parent[i * 2 + 1] = A;
  }

  vector<i32> ans(N * 2 + 2, 0);
  for (i32 i = 2; i <= 2 * N + 1; ++i) {
    ans[i] = ans[parent[i]] + 1;
  }

  for (i32 i = 1; i <= 2 * N + 1; ++i) {
    cout << ans[i] << '\n';
  }
}