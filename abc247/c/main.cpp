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

vector<i32> calc(i32 n) {
  if (n == 1) return {1};
  auto before = calc(n - 1);
  before.push_back(n);
  auto after = calc(n - 1);
  for (auto x : after) before.push_back(x);
  return before;
}

int main() {
  i32 N;
  cin >> N;
  auto res = calc(N);
  for (auto x : res) cout << x << " ";
}